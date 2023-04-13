#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<int> topological_sort(const vector<vector<int>> &G){
    int n = G.size();
    // 入次数を求める
    vector<int> indegree(n);
    for(int i = 0; i < n; i++){
        for(auto e: G[i]) indegree[e]++;
    }

    // 入次数0の頂点から取り除く
    // 辞書順最小を求めるためにpriority_queueを使用
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i = 0; i < n; i++) if(indegree[i] == 0) que.push(i);

    vector<int> order;
    while(!que.empty()){
        int pos = que.top(); que.pop();
        order.emplace_back(pos);
        for(auto e: G[pos]){
            indegree[e]--;
            if(indegree[e] == 0) que.push(e);
        }
    }

    return ((int)order.size() == n ? order : vector<int>{});
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> A(M);
    for(int i = 0; i < M; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int a; cin >> a, a--;
            A[i].emplace_back(a);
        }
    }

    // 筒の前後関係を有向グラフで表す
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int k = A[i].size();
        for(int j = 0; j < k - 1; j++){
            G[A[i][j]].emplace_back(A[i][j + 1]);
        }
    }


    auto order = topological_sort(G);
    // 有向グラフに閉路がなければYes
    cout << (!order.empty() ? "Yes" : "No") << endl;
}