#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    //dp[i][j] := i回ジャンプをして、jに到達することが可能か
    // 1: できる 0: できない
    vector<vector<int>> dp(n + 1,vector<int>(x + 1));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < x; j++){
            if(j + a[i] <= x) dp[i + 1][j + a[i]] |= dp[i][j];
            if(j + b[i] <= x) dp[i + 1][j + b[i]] |= dp[i][j];
        }
    }

    if(dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}