#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];

    // dp[i][j] := i番目までの品物の中から重さjを超えないように選んだときの価値の最大値
    vector<vector<ll>> dp(N+1,vector<ll>(W+1));
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= W; j++){
            if(0 <= j-w[i]) dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
            else dp[i+1][j] = dp[i][j];
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}