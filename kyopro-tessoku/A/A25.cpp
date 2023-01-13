#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> c(H);
    for(int i = 0; i < H; i++) cin >> c[i];

    // dp[i][j] := (i, j)に行く方法の数
    vector dp(H, vector<ll>(W));
    dp[0][0] = 1;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i+1 < H && c[i+1][j] == '.') dp[i+1][j] += dp[i][j];
            if(j+1 < W && c[i][j+1] == '.') dp[i][j+1] += dp[i][j];
        }
    }

    cout << dp[H-1][W-1] << endl;
}