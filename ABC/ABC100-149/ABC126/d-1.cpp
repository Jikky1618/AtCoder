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
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++){
        int u, v, w; cin >> u >> v >> w, u--, v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    vector<int> dist(N);
    // 任意の点からdfs
    auto dfs = [&](auto &&self, int pos, int p) -> void {
        for(auto [np, cost]: G[pos]){
            if(np == p) continue;
            dist[np] = dist[pos] + cost;
            self(self, np, pos);
        }
    };
    dfs(dfs, 0, -1);
    
    vector<int> ans(N);
    for(int i = 0; i < N; i++){
        if(dist[i] % 2 == 0) ans[i] = 1;
    }

    for(int i = 0; i < N; i++) cout << ans[i] << "\n";
}