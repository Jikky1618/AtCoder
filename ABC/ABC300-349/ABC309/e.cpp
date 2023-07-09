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
    for(int i = 1; i < N; i++){
        int p; cin >> p, p--;
        G[p].emplace_back(i);
    }

    // 木 DP
    // dp[i] := 頂点 i が加入している保険(-1: 未加入)
    vector<int> dp(N, -1);
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y, x--;
        // 最も末代に伝搬する保険を値に入れる
        if(dp[x] < y) dp[x] = y;
    }

    // 遷移
    auto dfs = [&](auto&&self, int pos, int par) -> void {
        for(auto np: G[pos]){
            if(np == par) continue;
            dp[np] = max(dp[np], dp[pos] - 1);
            self(self, np, pos);
        }
    };

    dfs(dfs, 0, -1);
    debug(dp);
    int ans = 0;
    for(int i = 0; i < N; i++) if(dp[i] >= 0) ans++;

    cout << ans << endl;
}