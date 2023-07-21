#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int LOG = 30;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;

    auto f = [&](int x) -> int { 
        string S = to_string(x);
        int sum = 0;
        for(auto c: S) sum += c - '0';
        return x - sum; 
    };

    // ダブリング
    // dp[k][i] := 数字 i を 2^k 回操作した後の値
    vector dp(LOG, vector<int>(N + 1));
    // 初期値
    for(int i = 0; i <= N; i++){
        dp[0][i] = f(i);
    }
    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i <= N; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }

    for(int i = 1; i <= N; i++){
        int ans = i;
        for(int j = 0; j < LOG; j++){
            if((K >> j) & 1){
                ans = dp[j][ans];
            }
        }
        cout << ans << '\n';
    }
}