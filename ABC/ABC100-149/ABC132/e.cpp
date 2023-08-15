#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(v);
    }
    int S, T;
    cin >> S >> T, S--, T--;
    debug(G);

    // 頂点倍加 BFS
    // dist[i][j] := 頂点 i をケンケンパーの j 歩目で到達するときの最短距離
    vector dist(N, vector<int>(3, -1));
    queue<pair<int, int>> que;
    dist[S][0] = 0;
    que.emplace(S, 0);
    while(!que.empty()){
        auto [pos, d] = que.front();
        que.pop();
        for(auto np: G[pos]){
            int nd = (d + 1) % 3;
            if(dist[np][nd] != -1) continue;
            dist[np][nd] = dist[pos][d] + 1;
            que.emplace(np, nd);
        }
    }

    cout << (dist[T][0] != -1 ? dist[T][0] / 3 : -1) << endl;
}