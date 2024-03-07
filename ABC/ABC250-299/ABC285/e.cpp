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
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // B[i] := 前の休日が i 日前のときの生産量
    vector<ll> B(N + 1);
    for(int i = 0; i < N; i++){
        B[i + 1] += B[i] + A[i / 2];
    }

    debug(B);
    // dp[i] := i 日目を休日としたときの最大の生産量
    vector<ll> dp(N + 1, 0);
    for(int i = 0; i < N + 1; i++){
        // 選ぶとき
        for(int j = 0; j < i; j++){
            dp[i] = max(dp[i], dp[j] + B[i - j - 1]);
        }
    }

    cout << dp[N] << endl;
}