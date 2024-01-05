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
        vector<ll> imos(K + 2);
        for(int j = 0; j <= K; j++){
            // [j, j + A[i] + 1) に dp[i][j] を加算
            imos[j] += dp[i][j];
            if(j + A[i] + 1 <= K + 1) imos[j + A[i] + 1] -= dp[i][j];
        }
        for(int j = 0; j <= K; j++){
            imos[j + 1] += imos[j];
        }
        // 増加分 imos[j] を dp[i + 1][j] に加算
        for(int j = 0; j <= K; j++){
            dp[i + 1][j] += imos[j], dp[i + 1][j] %= MOD;
        }
    }

    cout << dp[N][K] << endl;
}