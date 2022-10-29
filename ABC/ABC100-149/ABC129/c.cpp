#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    // ng[i] := 0なら壊れている
    vector<int> ng(n+1, 1);
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        ng[a] = 0;
    }

    // dpテーブル
    vector<int> dp(n+1);
    dp[0] = 1;
    if(ng[1]) dp[1] = 1;
    for(int i = 2; i <= n; i++){
        if(ng[i]) dp[i] += dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[n] << endl;
    return 0;
}