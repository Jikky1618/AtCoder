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
    string N;
    cin >> N;

    int M = N.size();
    ll ans = 0;
    // 割り切れる数を全探索
    for(int m = 1; m <= 9 * M; m++){
        // dp[m][smaller][j][k] := i 桁目まで見て、桁和が j, 値を m で割った余りが k であるような数の個数
        vector dp(M + 1, vector(2, vector(m + 1, vector<ll>(m))));
        dp[0][0][0][0] = 1;
        for(int i = 0; i < M; i++){
            for(int smaller = 0; smaller < 2; smaller++){
                for(int j = 0; j <= m; j++){
                    for(int k = 0; k < m; k++){
                        int lim = smaller ? 9 : N[i] - '0';
                        for(int d = 0; d <= lim; d++){
                            if(j + d > m) break;
                            dp[i + 1][smaller || d < lim][j + d][(k * 10 + d) % m] += dp[i][smaller][j][k];
                        }
                    }
                }
            }
        }
        ans += dp[M][0][m][0] + dp[M][1][m][0];
    }
    cout << ans << endl;
}