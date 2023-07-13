#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    const string T = "chokudai";
    int N = S.size(), M = T.size();
    // dp[i][j] := S の i 文字目までを見て, chokudai の j 文字目までを選択するパターン数
    vector dp(N + 1, vector<ll>(M + 1));
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            // S[i] が T[j] のとき, S[i] を選ぶときの遷移
            if(j < M && S[i] == T[j]) dp[i + 1][j + 1] += dp[i][j], dp[i + 1][j + 1] %= MOD;
            // S[i] を選ばないときの遷移
            dp[i + 1][j] += dp[i][j], dp[i + 1][j] %= MOD;
        }
    }

    cout << dp[N][M] << endl;
}