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
    int N, P;
    cin >> N >> P;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i] %= 2;

    // dp[i][j] := iまで食べたとき, 総和のあまりがjになる組み合わせ
    vector dp(N + 1, vector<ll>(2));
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            // 食べていないとき
            dp[i + 1][j] += dp[i][j];
            // 食べたとき
            dp[i + 1][(j + A[i]) % 2] += dp[i][j];
        }
    }

    cout << dp[N][P] << endl; 
}