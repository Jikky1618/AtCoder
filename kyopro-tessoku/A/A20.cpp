#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S, T;
    cin >> S >> T;

    int N = S.size(), M = T.size();

    // dp[i][j] := Sのi文字、Tのj文字までのLCS
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(S[i] == T[j] && i < N && j < M) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            if(i < N) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j < M) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
        }
    }

    cout << dp[N][M] << endl;
}