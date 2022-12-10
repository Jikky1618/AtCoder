#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int K, N, D;
    cin >> N >> K >> D;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    // dp[i][k][mod] := i番目までの整数からk個選んだ和をDで割ったときの値をvalとする
    //valの余りがmodになるときのvalの最大値
    vector dp(N+1,vector<vector<ll>>(K+1,vector<ll>(D, -1)));
    dp[0][0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int k = 0; k <= K; k++){
            for(int m = 0; m < D; m++){
                if(dp[i][k][m] == -1) continue;

                dp[i+1][k][m] = max(dp[i+1][k][m], dp[i][k][m]);
                if(k < K) dp[i+1][k+1][(m+a[i])%D] = max(dp[i+1][k+1][(m+a[i])%D], (dp[i][k][m] + a[i]));
            }
        }
    }

    cout << dp[N][K][0] << endl;
    return 0;
}