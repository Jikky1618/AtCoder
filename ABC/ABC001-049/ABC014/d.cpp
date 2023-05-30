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
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int x, y; cin >> x >> y, x--, y--;
        G[x].emplace_back(y), G[y].emplace_back(x);
    }

    // LCA を求める
    int L = 1;
    while((1 << L) < N) L++;
    vector parent(L, vector<int>(N, -1));

    // 1. 根からの距離, 1つ上の親を求める
    vector<int> dist(N, -1);
    auto dfs = [&](auto&& self, int pos, int p = -1) -> void {
        parent[0][pos] = p; // pos の 1 個上の親は p
        for(auto np: G[pos]){
            if(np == p) continue;
            dist[np] = dist[pos] + 1;
            self(self, np, pos);
        }
    };
    dfs(dfs, 0);
    debug(dist);

    // 2. 頂点 i の 2^L 個上の親を計算
    // ダブリング
    for(int i = 0; i + 1 < L; i++){
        for(int v = 0; v < N; v++){
            if(parent[i][v] == -1){
                parent[i + 1][v] = parent[i][v];
            }else{
                parent[i + 1][v] = parent[i][parent[i][v]];
            }
        }
    }

    // 3. 二分探索から LCA を求める
    auto query = [&](int u, int v) -> int {
        if(dist[u] < dist[v]) swap(u, v); // u のほうが深い頂点とする
        int K = parent.size();
        // u を v と同じ距離にする
        for(int i = 0; i < K; i++){
            if((dist[u] - dist[v]) & (1 << i)){
                u = parent[i][u];
            }
        }

        if(u == v) return u;
        for(int i = K - 1; i >= 0; i--){
            // LCA の直前まで u, v を移動させる
            if(parent[i][u] != parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        // 1つ上の親が LCA の頂点
        return parent[0][u];
    };

    int Q;
    cin >> Q;
    while(Q--){
        int a, b; cin >> a >> b, a--, b--;
        int lca = query(a, b);
        int ans = dist[a] + dist[b] - 2 * dist[lca] + 1;
        cout << ans << '\n';
    }
}