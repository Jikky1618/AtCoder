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
    int W, N, K;
    cin >> W >> N >> K;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // i 枚目まで見た時, 枚数が j で幅の合計が k のときの重要度の最大値
    vector dp(N + 1, vector(K + 1, vector<int>(W + 1)));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++){
            for(int k = 0; k <= W; k++){
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                if(j + 1 <= K && k + A[i] <= W){
                    dp[i + 1][j + 1][k + A[i]] = max(dp[i + 1][j + 1][k + A[i]], dp[i][j][k] + B[i]);
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= K; j++){
        for(int k = 0; k <= W; k++){
            ans = max(ans, dp[N][j][k]);
        }
    }

    cout << ans << endl;
}