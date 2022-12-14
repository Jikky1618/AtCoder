#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;
    // 何個選ぶかを全探索
    for(int m = 1; m <= N; m++){
        // dp[i][j][k] := a[i]までからj個選んだときの和をmで割ったときの余りがkになる場合の数
        vector dp(N+1, vector(N+1, vector<ll>(N+1)));
        dp[0][0][0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k < m; k++){
                    dp[i+1][j][k] += dp[i][j][k], dp[i+1][j][k] %= MOD;
                    if(j+1<=N) dp[i+1][j+1][(k+a[i])%m] += dp[i][j][k], dp[i+1][j+1][(k+a[i])%m] %= MOD;
                }
            }
        }
        ans += dp[N][m][0], ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}