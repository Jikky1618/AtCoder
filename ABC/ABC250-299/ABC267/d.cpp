#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // dp[i][j] := A_iまでのうち、j個,Bの要素として選んだときの最大値
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-LINF));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            // 選ばない場合
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            // 選ぶ場合
            if(j > 0) dp[i+1][j] = max(dp[i+1][j], dp[i][j-1]+a[i]*j);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}