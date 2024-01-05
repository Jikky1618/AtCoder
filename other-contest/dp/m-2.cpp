#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] := i 人目までの子供に j 個の飴を配るパターン数
    vector dp(N + 1, vector<ll>(K + 1));
    dp[0][0] = 1;

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j <= K; j++){
    //         for(int k = 0; k <= A[i]; k++){
    //             if(j + k <= K) dp[i + 1][j + k] += dp[i][j], dp[i + 1][j + k] %= MOD;
    //         }
    //     }
    // }

    for(int i = 0; i < N; i++){
        vector<ll> acc(K + 2);
        // 累積和で高速化
        for(int j = 0; j <= K; j++) acc[j + 1] += (acc[j] + dp[i][j]) % MOD;
        for(int j = 0; j <= K; j++){
            // [max(0, j - A[i]), j + 1) を dp[i][j] に加算
            dp[i + 1][j] = (acc[j + 1] - acc[max(0, j - A[i])] + MOD) % MOD;
        }
        debug(acc);
    }

    cout << dp[N][K] << endl;
}