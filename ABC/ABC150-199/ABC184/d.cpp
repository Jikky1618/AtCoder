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
    int A, B, C;
    cin >> A >> B >> C;

    // dp[a][b][c] := 金貨がa枚, 銀貨がb枚, 銅貨がc枚あるときの操作回数の期待値
    vector dp(101, vector(101, vector<double>(101)));

    // dp[100][100][100] = 0(操作をする必要がない)なので, そこからDPをする
    for(int a = 99; a >= A; a--){
        for(int b = 99; b >= B; b--){
            for(int c = 99; c >= C; c--){
                // dp[a][b][c] += 金貨の確率 * {a+1, b, c}枚あるときの期待値 + 1(操作回数)
                dp[a][b][c] += (double)a / (a + b + c) * (dp[a + 1][b][c] + 1);
                // dp[a][b][c] += 銀貨の確率 * {a, b+1, c}枚あるときの期待値 + 1(操作回数)
                dp[a][b][c] += (double)b / (a + b + c) * (dp[a][b + 1][c] + 1);
                // dp[a][b][c] += 銅貨の確率 * {a, b, c+1}枚あるときの期待値 + 1(操作回数)
                dp[a][b][c] += (double)c / (a + b + c) * (dp[a][b][c + 1] + 1);
            }
        }
    }

    cout << dp[A][B][C] << endl;
}