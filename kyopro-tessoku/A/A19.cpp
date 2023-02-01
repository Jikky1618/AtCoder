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
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];

    // dp[i][j] := i番目までの品物で重さがjのときの最大値
    vector dp(N + 1, vector<ll>(W + 1, -INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= W; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j + w[i] <= W) dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
        }
    }
    
    ll ans = 0;
    for(int i = 0; i <= W; i++){
        ans = max(ans, dp[N][i]);
    }

    cout << ans << endl;
}