#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int R, C, K;
    cin >> R >> C >> K;
    vector G(R, vector(C, 0));
    for(int i = 0; i < K; i++) {
        int r, c, v; cin >> r >> c >> v, r--, c--;
        G[r][c] = v;
    }

    // dp[i][j][k] := (i, j) にいるとき, i 行目で k 個拾っているときの最大値
    vector dp(R + 1, vector(C + 1, vector<ll>(4, -INF)));
    dp[0][0][0] = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            for(int k = 0; k <= 3; k++) {
                if(dp[i][j][k] == -INF) continue;
                // 横のマスに移動
                if(j + 1 < C) {
                    // 拾わない
                    dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
                    // 拾う
                    if(G[i][j] > 0 && k + 1 <= 3) {
                        dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + G[i][j]);
                    }
                }
                // 縦のマスに移動
                if(i + 1 < R) {
                    // 拾わない
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k]);
                    // 拾う
                    if(G[i][j] > 0 && k + 1 <= 3) {
                        dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k] + G[i][j]);
                    }
                }
            }
        }
    }

    debug(dp[R - 1][C - 1]);
    ll ans = 0;
    for(int k = 0; k <= 3; k++) {
        ans = max(ans, dp[R - 1][C - 1][k]);
        // (R - 1, C - 1) のアイテムも回収
        if(k + 1 <= 3) ans = max(ans, dp[R - 1][C - 1][k] + G[R - 1][C - 1]);
    }

    cout << ans << '\n';
}