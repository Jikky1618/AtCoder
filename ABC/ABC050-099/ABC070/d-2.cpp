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
        int a, b, c; cin >> a >> b >> c, a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    int Q, K;
    cin >> Q >> K, K--;

    vector<ll> dist(N, -1);
    dist[K] = 0;

    auto dfs = [&](auto &&self, int pos, int par, ll sum) -> void {
        dist[pos] = sum;
        for(auto [np, cost]: G[pos]){
            if(np == par) continue;
            self(self, np, pos, sum + cost);
        }
    };

    dfs(dfs, K, -1, 0);
    while(Q--){
        int x, y; cin >> x >> y, x--, y--;
        ll ans = dist[x] + dist[y];
        cout << ans << "\n";
    }
}