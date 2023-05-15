#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    vector<int> P(M), Q(M);
    for(int i = 0; i < M; i++) cin >> P[i] >> Q[i];

    // dp[i][S][T] := 訪問した場所の集合をS, 宝箱の集合をTとしたとき, 現在位置がiであるときの最小移動距離
    // 宝箱iのとき := i + N
    vector dp((1 << N), vector((1 << M), vector<double>(N + M, INF)));
    // 初期値は各街, 宝箱と原点との移動時間(最初は速度1なので距離のまま)
    for(int i = 0; i < N; i++) dp[1 << i][0][i] = hypot(X[i], Y[i]);
    for(int i = 0; i < M; i++) dp[0][1 << i][i + N] = hypot(P[i], Q[i]);

    for(int bit1 = 0; bit1 < (1 << N); bit1++){
        for(int bit2 = 0; bit2 < (1 << M); bit2++){
            int booster = (1 << __builtin_popcount(bit2));
            // 現在場所が街の場合
            for(int i = 0; i < N; i++){
                // 未到達ならcontinue
                if(dp[bit1][bit2][i] >= INF) continue;
                // 次の街に遷移
                for(int j = 0; j < N; j++){
                    if((bit1 >> j) & 1) continue; // すでに訪問済み
                    double t = hypot(X[i] - X[j], Y[i] - Y[j]) / booster;
                    dp[bit1 | (1 << j)][bit2][j] = min(dp[bit1 | (1 << j)][bit2][j], dp[bit1][bit2][i] + t);
                }
                // 次の宝箱に遷移
                for(int j = 0; j < M; j++){
                    if((bit2 >> j) & 1) continue; // すでに訪問済み
                    double t = hypot(X[i] - P[j], Y[i] - Q[j]) / booster;
                    dp[bit1][bit2 | (1 << j)][N + j] = min(dp[bit1][bit2 | (1 << j)][N + j], dp[bit1][bit2][i] + t);
                }
            }
            // 現在位置が宝箱の場合
            for(int i = 0; i < M; i++){
                // 未到達ならcontinue
                if(dp[bit1][bit2][N + i] >= INF) continue;
                // 次の街へ遷移
                for(int j = 0; j < N; j++){
                    if((bit1 >> j) & 1) continue; // すでに訪問済み
                    double t = hypot(P[i] - X[j], Q[i] - Y[j]) / booster;
                    dp[bit1 | (1 << j)][bit2][j] = min(dp[bit1 | (1 << j)][bit2][j], dp[bit1][bit2][N + i] + t);
                }
                // 次の宝箱へ遷移
                for(int j = 0; j < M; j++){
                    if((bit2 >> j) & 1) continue; // すでに訪問済み
                    double t = hypot(P[i] - P[j], Q[i] - Q[j]) / booster;
                    dp[bit1][bit2 | (1 << j)][N + j] = min(dp[bit1][bit2 | (1 << j)][N + j], dp[bit1][bit2][N + i] + t);
                }
            }
        }
    }

    double ans = INF;
    for(int i = 0; i < N; i++){
        for(int bit2 = 0; bit2 < (1 << M); bit2++){
            // 地点iから原点に戻るまでの時間を計算
            int booster = (1 << __builtin_popcount(bit2));
            double t = hypot(X[i], Y[i]) / booster;
            // 地点iの最短時間 + t の最小値が答え
            ans = min(ans, dp[(1 << N) - 1][bit2][i] + t);
        }
    }

    cout << ans << endl;
}