#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] := 状態(i, j)のときに最善を尽くした際のスコア
    vector dp(N, vector<int>(N));

    for(int i = 0; i < N; i++) dp[N - 1][i] = A[i];

    for(int i = N - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(i % 2 == 0) dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]);
            if(i % 2 == 1) dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    cout << dp[0][0] << endl;
}