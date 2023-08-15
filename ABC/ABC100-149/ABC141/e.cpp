#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 最長共通連続部分列を求める (最長共通部分列 = LCS とは異なる)
vector<vector<int>> longest_common_contiguous_subsequence(const string& S, const string& T) {
    int N = S.size(), M = T.size();
    // dp[i][j] := S の i 文字目と T の j 文字目を採用するときの最長共通連続部分文字列の長さ
    vector dp(N + 1, vector<int>(M + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // i 文字目と j 文字目が等しい場合
            if (S[i] == T[j]) {
                // 1 文字小さい文字列から遷移できる
                dp[i + 1][j + 1] = dp[i][j] + 1;
            // i 文字目と j 文字目が異なる場合
            } else {
                // 遷移することはできない
                dp[i + 1][j + 1] = 0;
            }
        }
    }

    return dp;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;

    // S, S の LCCS を解く
    auto dp = longest_common_contiguous_subsequence(S, S);
    debug(dp);
    int ans = 0;
    for(int i = 0; i <= N; i++){
        for(int j = i; j <= N; j++){
            // l1 + len <= l2 を満たしているか check
            if(i + dp[i][j] <= j){
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans << endl;
}