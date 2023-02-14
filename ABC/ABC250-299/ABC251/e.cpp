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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = INF;
    // 行動1を行うか行わないかで場合分け
    for(int type = 0; type <= 1; type++){
        // 行動iまでを行ったとき、行動iはj(1: 行う 0: 行わない)のときの合計費用の最小値
        vector dp(N + 1, vector<ll>(2));
        if(type == 0) dp[1][0] = 0, dp[1][1] = INF;
        if(type == 1) dp[1][0] = INF, dp[1][1] = A[0];
        for(int i = 1; i < N; i++){
            dp[i + 1][1] = min(dp[i][0], dp[i][1]) + A[i];
            dp[i + 1][0] = dp[i][1];
        }
        
        if(type == 0) ans = min(ans, dp[N][1]);
        if(type == 1) ans = min({ans, dp[N][0], dp[N][1]});
    }

    cout << ans << endl;
}