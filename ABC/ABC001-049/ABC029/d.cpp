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
    string N;
    cin >> N;

    int M = N.size();
    // 桁DP
    // dp[i][smaller][j] := i番目の桁まで決めたとき, 1を使った回数がkとなる数字の総パターン数
    vector dp(M + 1, vector(2, vector<ll>(M + 1)));
    dp[0][0][0] = 1;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            // smaller: 1 -> 1 の遷移
            // i + 1 桁目に 1 以外を選んだ場合 -> 遷移できるのは9通り(0, 2, 3, ..., 9)
            dp[i + 1][1][j] += dp[i][1][j] * 9;
            dp[i + 1][1][j + 1] += dp[i][1][j]; // i + 1 桁目に 1 を選んだ場合

            int ni = (N[i] - '0');
            // smaller: 0 -> 1 の遷移
            // ni が 1 の場合
            if(ni == 1){
                // i + 1 桁目は 0 を選ぶ他ない
                dp[i + 1][1][j] += dp[i][0][j];
            // 2 <= ni <= 9 の場合
            }else if(1 < ni){
                // i + 1 桁目に 1 を選んだ場合
                dp[i + 1][1][j + 1] += dp[i][0][j];
                // i + 1 桁目に 1 以外を選んだ場合 -> 遷移できるのは ni - 1 通り(0, 2, 3, ..., ni - 1)
                dp[i + 1][1][j] += dp[i][0][j] * (ni - 1);
            }

            // smaller: 0 -> 0 の遷移
            // ni が 1 の場合
            if(ni == 1){
                // j の数は1つ増える
                dp[i + 1][0][j + 1] += dp[i][0][j];
            // ni が 1 以外の場合
            }else{
                // j の数は変化しない
                dp[i + 1][0][j] += dp[i][0][j];
            }
        }
    }

    ll ans = 0;
    for(int j = 0; j < M + 1; j++) ans += j * (dp[M][1][j] + dp[M][0][j]);

    cout << ans << endl;
}