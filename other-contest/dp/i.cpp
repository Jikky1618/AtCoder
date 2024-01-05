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
    vector<double> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];

    // dp[i][j] := i 枚目まで確定したとき, 表が j 枚出る確率
    vector dp(N + 1, vector<double>(N + 1));
    dp[0][0] = 1.0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            // 「 j 枚が表」かつ「i 枚目が表」の確率
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            // 「 j 枚が表」かつ「i 枚目が裏」の確率
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
        }
    }

    double ans = 0;
    // ceil(N / 2) 枚以上表になる確率の総和が答え
    for(int i = (N + 1) / 2; i <= N; i++) ans += dp[N][i];

    cout << ans << endl;
}