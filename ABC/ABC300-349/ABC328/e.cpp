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
    ll K;
    cin >> N >> M >> K;

    vector<vector<pair<int, ll>>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v; ll c;
        cin >> u >> v >> c, u--, v--;
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }

    // dp[S] := 頂点集合 S の辺のコストの集合
    vector<set<ll>> dp(1 << N);
    dp[(1 << 0)].insert(0);

    for(int bit = 0; bit < (1 << N); bit++){
        for(int i = 0; i < N; i++){
            // 頂点 i が集合に含まれていない場合は continue
            if(!(bit & (1 << i))) continue;
            for(auto&& [to, c]: G[i]){
                // 頂点 to が既に含まれている場合は continue
                if(bit & (1 << to)) continue;
                // 辺 i - to のコストを追加
                for(auto&& cost: dp[bit]) dp[bit | (1 << to)].insert(cost + c);
            }
        }
    }

    ll ans = K;
    for(auto&& cost: dp[(1 << N) - 1]) ans = min(ans, cost % K);
    cout << ans << '\n';
}