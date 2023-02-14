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
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    // dp[i][j] := y[i]がj(true = 1, false = 0)になるようなx_0, x_1, ..., x_iの決め方
    vector dp(N + 1, vector<ll>(2));
    dp[0][0] = dp[0][1] = 1;
    for(int i = 0; i < N; i++){
        // y[i - 1]がj(true = 1, false = 0)のとき
        for(int j = 0; j <= 1; j++){
            // x[i]がk(true = 1, false = 0)のとき
            for(int k = 0; k <= 1; k++){
                if(S[i] == "OR"){
                    dp[i + 1][j | k] += dp[i][j];
                }
                if(S[i] == "AND"){
                    dp[i + 1][j & k] += dp[i][j];
                }
            }
        }
    }
    debug(dp);
    
    cout << dp[N][1] << endl;
}