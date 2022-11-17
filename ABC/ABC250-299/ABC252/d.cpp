#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAX 200005

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 同じ値の集合を作る
    map<int,int> mp;
    for(int i = 0; i < n; i++) mp[a[i]]++;

    // 値iの集合の個数を作る
    vector<int> cnt;
    for(auto &&i: mp) cnt.push_back(i.second);
    int m = cnt.size();

    // dp[i][j] := iまで確定していて、集合のサイズがjである通り数
    vector<vector<ll>> dp(MAX, vector<ll>(4));
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 4; j++){
            dp[i + 1][j] = dp[i][j];
            if(j > 0) dp[i + 1][j] += dp[i][j - 1] * cnt[i];
        }
    }

    cout << dp[m][3] << endl;
    return 0;
}