#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S, T;
    cin >> S >> T;

    int N = S.size(), M = T.size();
    // dp[i][j] := Sのi文字目、Tのj文字目までのLCS
    vector dp(N + 1, vector<int>(M + 1));
    dp[0][0] = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i + 1 <= N) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j + 1 <= M) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            if(i + 1 <= N && j + 1 <= M && S[i] == T[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }

    cout << dp[N][M] << endl;
}