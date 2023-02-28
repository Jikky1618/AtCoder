#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

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
    int N;
    string S;
    cin >> N >> S;

    string T = "atcoder";
    int M = T.size();

    // dp[i][j] := Sのi文字目まででatcoderのj文字目までの部分文字列になるパターン数
    vector dp(N + 1, vector<ll>(M + 1));
    dp[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            dp[i + 1][j] += dp[i][j], dp[i + 1][j] %= MOD;
            if(j < M && S[i] == T[j]) dp[i + 1][j + 1] += dp[i][j], dp[i + 1][j + 1] %= MOD;
        }
    }
    
    cout << dp[N][M] << endl;
}