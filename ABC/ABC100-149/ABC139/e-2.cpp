#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<int> topological_sort(const vector<vector<int>>& G) {
    int N = G.size();
    vector<int> indegree(N);
    for (int i = 0; i < N; i++) for (auto v : G[i]) indegree[v]++;
    queue<int> que;
    for (int i = 0; i < N; i++) if (indegree[i] == 0) que.emplace(i);
    vector<int> order;
    while (!que.empty()) {
        int from = que.front();
        que.pop();
        order.emplace_back(from);
        for (auto to : G[from]) {
            indegree[to]--;
            if (indegree[to] == 0) que.emplace(to);
        }
    }
    debug(order);
    // order が頂点数と一致しない場合は閉路が存在する
    return ((int)order.size() == N ? order : vector<int>());
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector A(N, vector<int>(N - 1));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++) cin >> A[i][j], A[i][j]--;
    }

    // id(i, j) := 試合 (i, j) の頂点番号を返す
    auto id = [&](int i, int j) -> int {
        if(i > j) swap(i, j);
        return j * (j - 1) / 2 + i;
    };

    // 試合を頂点とし、順序を向きとした有向グラフを構築
    int M = N * (N - 1) / 2;
    vector<vector<int>> G(M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 2; j++){
            int from = id(i, A[i][j]), to = id(i, A[i][j + 1]);
            G[from].emplace_back(to);
        }
    }

    // トポロジカルソートをしながら最長パスを求める。
    auto order = topological_sort(G);
    if(order.empty()){
        cout << -1 << endl;
        return 0;
    }

    // DAG 上の DP
    vector<int> dp(M);
    for(auto from: order){
        for(auto to: G[from]){
            dp[to] = max(dp[to], dp[from] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) + 1 << endl;
}