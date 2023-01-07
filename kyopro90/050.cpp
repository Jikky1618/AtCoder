#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, L;
    cin >> N >> L;

    // dp[i] := i段目にたどり着くまでの移動方法の数
    vector<ll> dp(N + 1);
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        dp[i + 1] += dp[i], dp[i + 1] %= MOD;
        if(i + L <= N) dp[i + L] += dp[i], dp[i + L] %= MOD;
    }

    cout << dp[N] << endl;
    return 0;
}