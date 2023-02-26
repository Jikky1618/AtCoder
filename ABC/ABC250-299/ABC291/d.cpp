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
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // dp[i] := i枚目が表のときの全パターン数
    // ep[i] := i枚目が裏のときの全パターン数
    vector<ll> dp(N), ep(N);
    dp[0] = ep[0] = 1;
    for(int i = 0; i < N - 1; i++){
        if(A[i + 1] != A[i]) dp[i + 1] += dp[i];
        if(A[i + 1] != B[i]) dp[i + 1] += ep[i];
        if(B[i + 1] != A[i]) ep[i + 1] += dp[i];
        if(B[i + 1] != B[i]) ep[i + 1] += ep[i];
        dp[i + 1] %= MOD, ep[i + 1] %= MOD;
    }
    
    cout << (dp[N - 1] + ep[N - 1]) % MOD << endl;
}