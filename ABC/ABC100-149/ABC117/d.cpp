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
    std::cout << fixed << setprecision(20);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    constexpr int LOG = 40;
    // 桁 DP
    // dp[i][smaller] := 「上から」 i 番目の桁まで決めたときの f の最大値
    vector dp(LOG + 1, vector<ll>(2, -1));
    dp[0][0] = 0;
    for(ll i = 0; i < LOG; i++){
        // A の i 桁目に立っている bit の数
        ll cnt = 0;
        for(int j = 0; j < N; j++) if((A[j] >> i) & 1) cnt++;

        // cost0 := i 桁目に 0 を選んだ場合
        // i 桁目に立っている bit の数分増える
        ll p0 = cnt * (1 << i);
        ll p1 = (N - cnt) * (1 << i);

        // smaller: 1 -> 1 への遷移
        if(dp[i][1] != -1){
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + max(p0, p1));
        }
        // smaller: 0 -> 1 への遷移
        if(dp[i][0] != -1){
            if((K >> i) & 1){
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + p0); 
            }
        }
        // smaller: 0 -> 0 への遷移
        if(dp[i][0] != -1){
            if((K >> i) & 1){
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + p1);
            }else{
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + p0);
            }
        }
    }
    debug(dp);
    debug(dp[LOG]);
    std::cout << max(dp[LOG][0], dp[LOG][1]) << endl;
}