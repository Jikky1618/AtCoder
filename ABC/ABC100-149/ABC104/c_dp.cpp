#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;
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
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    for(int i = 0; i < D; i++) cin >> p[i] >> c[i];

    int sum = 0;
    for(int i = 0; i < D; i++) sum += p[i];

    // dp[i][j] := i番目の問題までで、j問解いたときの最大得点
    vector dp(D + 1, vector<int>(sum + 1, -INF));
    dp[0][0] = 0;
    for(int i = 0; i < D; i++){
        for(int j = 0; j <= sum; j++){
            for(int k = 0; k <= p[i]; k++){
                if(j + k > sum) continue; 
                dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + k * (i + 1) * 100);
                if(k == p[i]) dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + k * (i + 1) * 100 + c[i]);
            }
        }
    }

    int ans = INF;
    for(int j = 0; j <= sum; j++){
        if(G <= dp[D][j]) ans = min(ans, j);
    }

    cout << ans << endl;
}