#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;

    vector<int> A(N);
    for (int i = 0; i < N; i++) A[i] = S[i] - '0';

    // dp[i][j] := i 文字目まで見たとき, 値が j になる組合せ
    vector dp(N + 1, vector<ll>(2, 0));
    for (int i = 0; i < N; i++) {
        // A[i] の値で場合分け
        if (A[i] == 0) {
            dp[i + 1][0] += 1;
            dp[i + 1][1] += dp[i][0] + dp[i][1];
        }
        if (A[i] == 1) {
            dp[i + 1][0] += dp[i][1];
            dp[i + 1][1] += dp[i][0] + 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i <= N; i++) ans += dp[i][1];
    cout << ans << '\n';
}