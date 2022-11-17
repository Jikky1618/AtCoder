#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    // dp[i][j][k] := i番目までの品物の中から
    // たこ焼きj個、たいやきk個を買うことができるときの弁当の個数の最小値
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(x+1, vector<int>(y+1, INF)));
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            for(int k = 0; k <= y; k++){
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][min(j+a[i],x)][min(k+b[i],y)] = min(dp[i+1][min(j+a[i],x)][min(k+b[i],y)], dp[i][j][k] + 1);
            }
        }
    }

    if(dp[n][x][y] == INF) cout << -1 << endl;
    else cout << dp[n][x][y] << endl;
    return 0;
}