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
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // ゲームDP
    // dp[i][j] := すでにi枚取られているときターンがj(j = 0: 先手, j = 1: 後手)の場合のスコアの最適値
    vector dp(N, vector<ll>(2));
    for(int i = N - 1; i >= 0; i--){
        // 先手
        dp[i][0] = -INF; // 初期化
        // 後手側のカードの数字(i = 0 のとき, W)
        ll Y = (i ? A[i - 1] : W);
        // 全ての山札を取った場合
        dp[i][0] = max(dp[i][0], abs(Y - A[N - 1]));
        for(int j = i + 1; j < N; j++){
            dp[i][0] = max(dp[i][0], dp[j][1]);
        }

        // 後手
        dp[i][1] = INF; // 初期化
        // 先手側のカードの数字(i = 0 のとき, Z)
        ll X = (i ? A[i - 1] : Z);
        // 全ての山札を取った場合
        dp[i][1] = min(dp[i][1], abs(X - A[N - 1]));
        for(int j = i; j < N; j++){
            dp[i][1] = min(dp[i][1], dp[j][0]);
        }
    }

    cout << dp[0][0] << endl;
}