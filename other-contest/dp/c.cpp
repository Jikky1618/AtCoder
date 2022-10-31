#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    // dp[i][j] := i日目にj(0:A,1:B,2:C)するとき、i日目までに得る満足度
    vector<vector<int>> dp(n+1,vector<int>(3));
    for(int j = 0; j < 3; j++) dp[0][j] = 0;
    for(int i = 0; i < n; i++){
        // i+1日目にAを選択
        dp[i+1][0] = max(dp[i][1]+b[i], dp[i][2]+c[i]);
        // i+1日目にBを選択
        dp[i+1][1] = max(dp[i][0]+a[i],dp[i][2]+c[i]);
        // i+1日目にCを選択
        dp[i+1][2] = max(dp[i][0]+a[i],dp[i][1]+b[i]);
    }

    int ans = *max_element(dp[n].begin(), dp[n].end());
    cout << ans << endl;
    return 0;
}