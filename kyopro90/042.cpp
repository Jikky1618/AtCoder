#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

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
    int K;
    cin >> K;
    
    if(K % 9 == 0){
        // dp[i] := 各桁の和がiのときのパターン数
        vector<ll> dp(K + 1);
        dp[0] = 1;

        for(int i = 0; i < K; i++){
            for(int j = 1; j <= 9; j++){
                if(i + j <= K) dp[i + j] += dp[i], dp[i + j] %= MOD;
            }
        }
        cout << dp[K] << endl;
    }else{
        cout << 0 << endl;
    }
}