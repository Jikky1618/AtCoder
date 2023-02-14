#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    vector dp(N + 1, vector<ll>(2, -INF));
    dp[0][0] = 1, dp[0][1] = 1;
    for(int i = 0; i < N; i++){
        if(S[i] == "OR"){
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1] * 2 + dp[i][0];
        }
        if(S[i] == "AND"){
            dp[i + 1][0] = dp[i][0] * 2 + dp[i][1];
            dp[i + 1][1] = dp[i][1];
        }
    }
    
    cout << dp[N][1] << endl;
}