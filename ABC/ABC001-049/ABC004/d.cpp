#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int INF = (1 << 30) - 1;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int R, G, B;
    cin >> R >> G >> B;

    // R, G, B のスタート地点をずらす
    const int r = 400, g = 500, b = 600, N = 1000;
    // dp[i][j] := i 番目の箱を見ているとき, マーブル数を j 個置いたときの最小コスト
    // R -> G -> B の順に置いていくので, R, G, B の個数は持たなくてよい
    vector dp(N + 1, vector<int>(R + G + B + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= R + G + B; j++) {
            // 置かない場合
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            // i 番目の箱に R を置く場合
            if (j < R) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(r - i));
            }
            // i 番目の箱に G を置く場合
            else if (j < R + G) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(g - i));
            }
            // i 番目の箱に B を置く場合
            else if (j < R + G + B) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(b - i));
            }
        }
    }

    cout << dp[N][R + G + B] << '\n';
}