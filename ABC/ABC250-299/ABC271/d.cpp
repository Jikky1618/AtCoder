#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,s;
    cin >> n >> s;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    // dp[i][j] := カード1,2,...,iを使い、合計をjにできるか
    // 1: できる 0: できない
    vector<vector<int>> dp(n+1,vector<int>(s+1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            if(0 <= j-a[i]) dp[i][j] |= dp[i-1][j-a[i]];
            if(0 <= j-b[i]) dp[i][j] |= dp[i-1][j-b[i]];
        }
    }

    // dp判定
    if(dp[n][s]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
        return 0;
    }

    // dp復元
    string ans;
    int val = s;
    for(int i = n; i > 0; i--){
        if(val-a[i] >= 0 && dp[i-1][val-a[i]]){
            ans.push_back('H');
            val -= a[i];
        }else{
            ans.push_back('T');
            val -= b[i];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}