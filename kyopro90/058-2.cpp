#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int LOG = 60;
const int MOD = 100000;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, K;
    cin >> N >> K;

    auto f = [&](int x) -> int {
        string S = to_string(x);
        int y = 0;
        for(auto c: S) y += c - '0';
        return (x + y) % MOD;
    };

    // ダブリング
    // dp[k][i] := i から 2^k 回操作後の値
    vector dp(LOG, vector<int>(MOD));
    // 初期値
    for(int i = 0; i < MOD; i++){
        dp[0][i] = f(i);
    }
    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < MOD; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }

    int ans = N;
    for(int i = 0; i < LOG; i++){
        if((K >> i) & 1){
            ans = dp[i][ans];
        }
    }

    cout << ans << endl;
}