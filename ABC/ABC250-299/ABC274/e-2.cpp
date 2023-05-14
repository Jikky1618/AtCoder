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
    vector<int> X(N + M), Y(N + M);
    for(int i = 0; i < N + M; i++){
        cin >> X[i] >> Y[i];
    }
    vector d(N + M, vector<double>(N + M));
    for(int i = 0; i < N + M; i++){
        for(int j = 0; j < N + M; j++){
            d[i][j] = hypot(X[i] - X[j], Y[i] - Y[j]);
        }
    }

    // N + M 個地点のTSPをとりあえず解く
    // dp[i][S] := 今まで訪れた地点(街 or 宝箱)の集合をS, 今いる地点をiとしたときの最短距離
    vector dp((1 << (N + M)), vector<double>(N + M, INF));
    
    // 初期値は原点から各地点までの移動時間
    for(int i = 0; i < N + M; i++){
        dp[1 << i][i] = hypot(X[i], Y[i]);
    }

    for(int bit = 0; bit < (1 << (N + M)); bit++){
        for(int i = 0; i < N + M; i++){
            if(dp[bit][i] >= INF) continue;
            for(int j = 0; j < N + M; j++){
                if((bit >> j) & 1) continue; // すでに訪問済み
                int booster = __builtin_popcount(bit >> N);
                double t = d[i][j] / (1 << booster);
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + t);
            }
        }
    }

    double ans = INF;
    for(int i = 0; i < N + M; i++){
        for(int bit = 0; bit < (1 << (N + M)); bit++){
            // もし全ての街を訪問済みなら
            if((bit & ((1 << N) - 1)) == (1 << N) - 1){
                // 地点iから原点に戻るまでの時間を計算
                int booster = __builtin_popcount(bit >> N);
                double t = hypot(X[i], Y[i]) / (1 << booster);
                // dp[bit][i] + t の最小値が答え
                ans = min(ans, dp[bit][i] + t);
            }
        }
    }

    cout << ans << endl;
}