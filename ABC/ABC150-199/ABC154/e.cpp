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
    int K;
    cin >> N >> K;

    int M = N.size();
    // dp[i][smaller][j] := 上から i 桁目まで見たとき, 0 でない数字が j 個ある数字の個数
    vector dp(M + 1, vector(2, vector<ll>(K + 1)));
    dp[0][0][0] = 1;
    for(int i = 0; i < M; i++){
        for(int smaller = 0; smaller < 2; smaller++){
            for(int j = 0; j <= K; j++){
                int lim = smaller ? 9 : N[i] - '0';
                for(int k = 0; k <= lim; k++){
                    // すでに 0 でない数が K 個の場合は 0 以外で遷移不可
                    if(j == K && k > 0) break;
                    dp[i + 1][smaller || k < lim][j + (k != 0)] += dp[i][smaller][j];
                }
            }
        }
    }

    cout << dp[M][0][K] + dp[M][1][K] << '\n';
}