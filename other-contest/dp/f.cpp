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
    // dp[i][j] := S の i 文字目までと T の j 文字目までの LCS の長さ
    // i, j is 0-indexed
    vector dp(N + 1, vector<int>(M + 1));

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            // S[i] と T[j] が一致するとき
            if(i < N && j < M && S[i] == T[j]){
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            // S[i + 1] <- S[i] に遷移
            if(i + 1 <= N){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
            // T[j + 1] <- T[j] に遷移
            if(j + 1 <= M){
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            }
        }
    }

    // 復元
    string ans = "";
    int i = N, j = M;
    while(i > 0 && j > 0){
        // dp[i - 1][j - 1] -> dp[i][j] に遷移していたとき
        if(S[i - 1] == T[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1){
            ans = S[i - 1] + ans;
            i--; j--;
            continue;
        }
        // dp[i - 1][j] -> dp[i][j] に遷移していたとき
        if(dp[i][j] == dp[i - 1][j]){
            i--;
            continue;
        }
        // dp[i][j - 1] -> dp[i][j] に遷移していたとき
        if(dp[i][j] == dp[i][j - 1]){
            j--;
            continue;
        }
    }

    cout << ans << endl;
}