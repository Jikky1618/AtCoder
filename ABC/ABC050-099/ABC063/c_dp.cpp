#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    // dp[i][j] := i番目までを選んで値をjにできるか
    vector dp(N+1, vector<int>(10010));
    dp[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10010; j++){
            if(j + S[i] < 10010) dp[i + 1][j + S[i]] |= dp[i][j];
            dp[i + 1][j] |= dp[i][j];
        }
    }

    int ans = 0;
    for(int j = 0; j < 10010; j++) if(dp[N][j] && j % 10 != 0) ans = max(ans, j);

    cout << ans << endl;
}v