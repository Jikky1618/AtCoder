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
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    const int LOG = 40;
    // ダブリング
    // dp[k][i] := i(X mod N) 個アメが皿にあるとき, 2^k 回の操作で到着する A の index
    // val[k][i] := i(X mod N) 個アメが皿にあるとき, 2^k 回の操作で追加されるアメの「総数」
    vector dp(LOG, vector<ll>(N));
    vector val(LOG, vector<ll>(N));
    for(int i = 0; i < N; i++){
        // 1 回の操作で, i + A[i] 個になる
        dp[0][i] = (i + A[i]) % N;
        // 1 回の操作で, A[i] 個追加される
        val[0][i] = A[i];
    }
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < N; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
            // 2^(k + 1) 回までに追加される総数
            // = 2^k 回までに追加された総数 + これから 2^k 回操作を行って追加される総数
            val[k + 1][i] = val[k][i] + val[k][dp[k][i]];
        }
    }

    ll ans = 0;
    int pos = 0;
    for(int i = 0; i < LOG; i++){
        if((K >> i) & 1){
            ans += val[i][pos];
            pos = dp[i][pos];
        }
    }

    cout << ans << endl;
}