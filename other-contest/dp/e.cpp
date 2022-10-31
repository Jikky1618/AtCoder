#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];

    // dp[i][j] := i番目までの品物の中から価値がj以上になる重さの最小値
    // j_max = 100 * 10^3
    vector<vector<ll>> dp(N+1, vector<ll>(10010, LINF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 10000; j++){
            if(0 <= j-v[i]) dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
            else dp[i+1][j] = dp[i][j];
        }
    }

    for(auto &&i: dp){
        for(auto &&j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}