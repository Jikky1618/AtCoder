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
    string S;
    cin >> S;

    auto NAND = [&](int i, int j) -> int {
        return 1 - min(i, j);
    };

    // dp[i + 1][j] := S[i] までで値が j になるパターン数
    vector dp(N + 1, vector<ll>(2));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            dp[i + 1][NAND(j, S[i] - '0')] += dp[i][j];
        }
        dp[i + 1][S[i] - '0']++;
    }

    ll ans = 0;
    for(int i = 1; i <= N; i++) ans += dp[i][1];

    cout << ans << endl;
}