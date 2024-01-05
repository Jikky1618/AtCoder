#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

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
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    // dp[i][j] := 頂点 i の色が j (0:黒, 1:白) のときのパターン数
    vector dp(N, vector<ll>(2));
    auto dfs = [&](auto&& self, int pos, int par) -> void {
        dp[pos][0] = dp[pos][1] = 1;
        // pos が葉なら return 
        if(pos != 0 && G[pos].size() == 1) return;

        for(auto np: G[pos]){
            if(np == par) continue;
            self(self, np, pos);
            // pos が黒色のパターン数
            dp[pos][0] *= dp[np][1], dp[pos][0] %= MOD;
            // pos が白色のパターン数
            dp[pos][1] *= dp[np][0] + dp[np][1], dp[pos][1] %= MOD;
        }
    };
    dfs(dfs, 0, -1);

    ll ans = (dp[0][0] + dp[0][1]) % MOD;
    cout << ans << endl;
}