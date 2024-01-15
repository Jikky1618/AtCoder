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
    int N; ll K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    const int LOG = 40;
    // dp[i][smaller] := 上から i 桁目まで見たときの最大値
    vector dp(LOG + 1, vector<ll>(2, -1));
    dp[0][0] = 0;
    for(int i = 0; i < LOG; i++){
    // 上から i 桁目の mask
    ll mask = 1LL << (LOG - i - 1), cnt = 0;
    // i 桁目で A で 1 が立っているものの個数を求める
    for(int j = 0; j < N; j++) if(A[j] & mask) cnt++;
        // 遷移
        // 1 -> 1
        if(dp[i][1] != -1){
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + mask * max(cnt, N - cnt));
        }
        // 0 -> 1 (K の i 桁目が 1 である場合のみ遷移)
        if(dp[i][0] != -1 && (K & mask)){
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + mask * cnt);
        }
        // 0 -> 0
        if(dp[i][0] != -1){
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + mask * ((K & mask) ? N - cnt : cnt));
        }
    }

    ll ans = max(dp[LOG][0], dp[LOG][1]);
    cout << ans << endl;
}