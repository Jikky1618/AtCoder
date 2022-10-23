#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
 
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
 
    int n = s.size();
    string t = "chokudai";
    // dp[i][j] := Sのi文字目までにchokudaiのj文字目まで選択する方法
    vector<vector<int>> dp(n + 1,vector<int>(9));
 
    // chokudaiの0文字目までの選択は下線をなにも引いていない状態(1通り)
    for(int i = 0; i < n + 1; i++) dp[i][0] = 1;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 8; j++){
            if(s[i] == t[j]){
                dp[i + 1][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }else{
                dp[i + 1][j + 1] = dp[i][j + 1] % MOD;
            }
        }
    }
 
    cout << dp[n][8] << endl;
    return 0;
}