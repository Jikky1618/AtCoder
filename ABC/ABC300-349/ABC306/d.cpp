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
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    // dp[i][j] := i番目のとき, 高橋くんの状態が j のときの最大値
    vector dp(N + 1, vector<ll>(2, -INF));
    dp[0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            // 食べない場合
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            // 食べる場合
            // i番目が解毒剤入り
            if(X[i] == 0){
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + Y[i]);
            }
            // i番目は毒入り
            if(X[i] == 1){
                if(j == 0) dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + Y[i]);
            }
        }
    }

    debug(dp);
    ll ans = max(dp[N][0], dp[N][1]);
    cout << ans << endl;
}