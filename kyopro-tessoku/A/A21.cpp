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
    int N;
    cin >> N;
    vector<int> P(N), A(N);
    for(int i = 0; i < N; i++) cin >> P[i] >> A[i], P[i]--;

    // dp[l][r] := lからr番目まで残っているとき、得点の最大値
    vector dp(N + 1, vector<int>(N + 1));

    for(int Length = N - 1; Length >= 0; Length--){
        for(int l = 0; l < N; l++){
            int r = l + Length;
            if(r > N) break;

            if(l - 1 >= 0){
                int p1 = (l - 1 <= P[l - 1] && P[l - 1] < r ? A[l - 1] : 0);
                dp[l][r] = max(dp[l][r], dp[l - 1][r] + p1);
            }
            if(r + 1 <= N){
                int p2 = (l <= P[r] && P[r] < r + 1 ? A[r] : 0);
                dp[l][r] = max(dp[l][r], dp[l][r + 1] + p2);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(ans, dp[i][i]);

    cout << ans << endl;
}