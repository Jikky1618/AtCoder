#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    // dp[i] := i円引き出すのにかかる最低操作回数
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        // 1円
        dp[i+1] = min(dp[i+1], dp[i]+1);
        // 6^x円
        int x = 6;
        while(i+x <= n){
            dp[i+x] = min(dp[i+x], dp[i]+1);
            x *= 6;
        }
        // 9^x円
        x = 9;
        while(i+x <= n){
            dp[i+x] = min(dp[i+x], dp[i]+1);
            x *= 9;
        }
    }

    cout << dp[n] << endl;
    return 0;
}