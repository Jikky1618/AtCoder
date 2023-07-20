#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int LOG = 35;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, X, M;
    cin >> N >> X >> M;

    auto f = [&](ll x) -> int { 
        return (x * x) % M;
    };
    // ダブリング
    // dp[k][i] := i から 2^k 回操作した後の値 A_(2^k)
    // val[k][i] := i から 2^k 項までの総和
    vector dp(LOG, vector<int>(M));
    vector val(LOG, vector<ll>(M));
    // 初期値
    for(int i = 0; i < M; i++){
        dp[0][i] = f(i);
        val[0][i] = i;
    }

    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < M; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
            val[k + 1][i] = val[k][i] + val[k][dp[k][i]];
        }
    }

    int pos = X;
    ll ans = 0;
    for(int i = 0; i < LOG; i++){
        if((N >> i) & 1){
            debug(val[i][pos]);
            ans += val[i][pos];
            pos = dp[i][pos];
        }
    }

    cout << ans << endl;
}