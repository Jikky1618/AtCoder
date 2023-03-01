#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] := i回目の操作後の一番左の値がjとなるパターン数
    vector dp(N, vector<ll>(10));
    dp[0][A.front()] = 1;

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < 10; j++){
            int F = (j + A[i + 1]) % 10, G = (j * A[i + 1]) % 10;
            dp[i + 1][F] += dp[i][j], dp[i + 1][F] %= MOD;
            dp[i + 1][G] += dp[i][j], dp[i + 1][G] %= MOD;
        }
    }
    
    for(int i = 0; i < 10; i++){
        cout << dp[N - 1][i] << endl;
    }
}