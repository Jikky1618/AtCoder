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
    // 入次数を求める
    vector<int> indegree(N);
    for (int i = 0; i < N; i++) {
        for (auto e : G[i]) indegree[e]++;
    }

    // 入次数 0 の頂点から取り除く
    queue<int> que;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) que.emplace(i);
    }

    vector<int> order;
    while (!que.empty()) {
        // que の先頭の頂点を取り出す
        int pos = que.front();
        que.pop();

        // 頂点 pos を order に追加
        order.emplace_back(pos);
        // pos と隣接している頂点の入次数を 1 下げる
        for (auto e : G[pos]) {
            indegree[e]--;
            // 0 になれば, que に追加
            if (indegree[e] == 0) que.emplace(e);
        }
    }

    return ((int)order.size() == N ? order : vector<int>());
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> C(N);
    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        cin >> C[i];
        G[i].resize(C[i]);
        for(int j = 0; j < C[i]; j++) cin >> G[i][j], G[i][j]--;
    }
    debug(C, G);

    // 本 1 を読むのに必要な本を BFS で求める
    vector<int> seen(N);
    queue<int> que;
    seen[0] = true;
    que.emplace(0);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(seen[np]) continue;
            seen[np] = true;
            que.emplace(np);
        }
    }
    debug(seen);

    // 本 1 を読むのに必要な本のみでグラフを作成
    vector<vector<int>> G2(N);
    for(int i = 0; i < N; i++){
        if(!seen[i]) continue;
        for(auto np: G[i]){
            if(!seen[np]) continue;
            G2[i].emplace_back(np);
        }
    }
    debug(G2);

    auto order = topological_sort(G2);
    debug(order);
    for(unsigned i = order.size() - 1; i > 0; i--){
        if(!seen[order[i]]) continue;
        cout << order[i] + 1 << " \n"[i == 1];
    }
}