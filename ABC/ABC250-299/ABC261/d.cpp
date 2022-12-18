#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<ll> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];
    vector<ll> C(M), Y(M);
    for(int i = 0; i < M; i++) cin >> C[i] >> Y[i];

    // ボーナスの配列を作成する
    vector<ll> B(N+1);
    for(int i = 0; i < M; i++) B[C[i] - 1] = Y[i];

    // dp[i][j] := i回目でカウンタがjのときの最大値
    vector dp(N+1, vector<ll>(N+1, -INF));
    dp[0][0] = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // 表のとき
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+X[i]+B[j]);
            // 裏のとき
            dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
        }
    }

    ll ans = 0;
    for(int j = 0; j <= N; j++) ans = max(ans, dp[N][j]);

    cout << ans << endl;
    return 0;
}