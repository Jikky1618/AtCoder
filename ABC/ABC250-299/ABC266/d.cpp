#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1LL << 60;
#define M 100005

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    // 入力は時間ベース
    vector<ll> x(M),a(M);
    for(int i = 0; i < n; i++){
        ll T,X,A; cin >> T >> X >> A;
        x[T] = X;
        a[T] = A;
    }

    // dp[i][j] := 時刻iに穴jの上にいるときの、大きさの最大値
    vector<vector<ll>> dp(M,vector<ll>(5,-LINF));
    dp[0][0] = 0;
    for(int i = 0; i < M-1; i++){
        for(int j = 0; j < 5; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j != 4) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j + 1]);
            if(j != 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
        dp[i+1][x[i+1]] += a[i+1];
    }

    ll ans = -LINF;
    for(int i = 0; i < 5; i++) ans = max(ans, dp[M-1][i]);

    cout << ans << endl;
    return 0;
}