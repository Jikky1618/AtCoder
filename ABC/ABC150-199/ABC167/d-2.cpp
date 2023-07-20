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
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;

    const int LOG = 60;
    // ダブリング
    // dp[k][i] := 街 i から 2^k 回テレポーターを使ったときの到着する街
    vector dp(LOG, vector<int>(N));
    // 1 回テレポーターを使ったときの到着する街が初期値
    for(int i = 0; i < N; i++){
        dp[0][i] = A[i];
    }

    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < N; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }
    debug(dp);

    int ans = 0;
    for(int i = 0; i < LOG; i++){
        if((K >> i) & 1) ans = dp[i][ans];
    }

    cout << ans + 1 << endl;
}