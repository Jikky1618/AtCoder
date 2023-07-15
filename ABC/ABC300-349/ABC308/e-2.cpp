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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    string S;
    cin >> S;

    // dp[i][j][k] := i番目までの文字列を見て"MEX"の j 文字目までを選択したとき, A[i] の bit が k になるパターン数
    vector dp(N + 1, vector(4, vector<ll>(1 << 3)));
    dp[0][0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 3; j++){
            for(int k = 0; k < (1 << 3); k++){
                // S[i] を選択しない
                dp[i + 1][j][k] += dp[i][j][k];
                // MEX 全てを選んでいない場合
                if(j < 3){
                    // S[i] を選択する場合
                    if(S[i] == "MEX"[j]){
                        // k に A[i] bit を建てる
                        dp[i + 1][j + 1][k | (1 << A[i])] += dp[i][j][k];
                    }
                }
            }
        }
    }

    ll ans = 0;
    // 全ての A[i] の bit のパターンに対して mex とパターン数を求める
    for(int k = 0; k < (1 << 3); k++){
        int mex = 0;
        // mex を求める
        while((k >> mex) & 1) mex++;
        debug(mex);
        ans += dp[N][3][k] * mex;
    }

    cout << ans << endl;
}