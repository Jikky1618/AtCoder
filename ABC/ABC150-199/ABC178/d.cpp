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
    int S;
    cin >> S;

    // dp[i] := 総和がiになるような数列の数
    vector<ll> dp(S + 1);
    dp[0] = 1;
    for(int i = 0; i < S; i++){
        for(int j = 3; j <= S; j++){
            if(i + j <= S) dp[i + j] += dp[i], dp[i + j] %= MOD;
        }
    }

    cout << dp[S] << endl;
}