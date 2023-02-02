#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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

    // dp[i][j] := Sのi文字目、Tのj文字目までの編集距離
    vector dp(N + 1, vector<int>(M + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i <= N; i++) dp[i][0] = i;
    for(int j = 0; j <= M; j++) dp[0][j] = j;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(S[i] == T[j]){
                dp[i + 1][j + 1] = min({dp[i + 1][j + 1], dp[i][j], dp[i][j + 1] + 1, dp[i + 1][j] + 1});
            }else{
                dp[i + 1][j + 1] = min({dp[i + 1][j + 1], dp[i][j] + 1, dp[i][j + 1] + 1, dp[i + 1][j] + 1});
            }
        }
    }
    debug(dp);
    cout << dp[N][M] << endl;
}