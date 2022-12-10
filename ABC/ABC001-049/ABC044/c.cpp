#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAX 3000

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    for(int i = 0; i < N; i++) cin >> x[i];

    // dp[i][j][k] := i番目のカードまでにj枚選んだとき、総和がkになる個数
    vector dp(N+1, vector<vector<ll>>(N+1, vector<ll>(MAX)));
    dp[0][0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k < MAX; k++){
                if (dp[i][j][k] == 0) continue;

                dp[i+1][j][k] += dp[i][j][k];
                if(j < N && k+x[i] <= MAX) dp[i+1][j+1][k+x[i]] += dp[i][j][k];
            }
        }
    }

    ll ans = 0;
    for(int j = 1; j <= N; j++){
        ans += dp[N][j][A * j];
    }

    cout << ans << endl;
    return 0;
}