#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,m,k;
    cin >> n >> m >> k;

    // dp[i][j] := 長さiで和がjの数列の数
    vector<vector<ll>> dp(n+1,vector<ll>(k+1));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            for(int x = 1; x <= m; x++){
                if(j + x <= k) dp[i + 1][j + x] += dp[i][j], dp[i + 1][j + x] %= MOD;
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i <= k; i++){
        ans += dp[n][i], ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}