#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MOD = 998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    // dp[i][j] := i番目の値がjのときの場合の数
    vector dp(N + 1, vector<ll>(3001));
    dp[0][0] = 1;

    for(int i = 0; i < N; i++){
        dp[i + 1][0] = dp[i][0];
        for(int j = 0; j < 3000; j++){
            dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
        }
        for(int j = 0; j < A[i]; j++){
            dp[i + 1][j] = 0;
        }
        for(int j = B[i] + 1; j <= 3000; j++){
            dp[i + 1][j] = 0;
        }
    }

    ll ans = 0;
    for(int i = 0; i <= 3000; i++) ans += dp[N][i], ans %= MOD;

    cout << ans << endl;
}