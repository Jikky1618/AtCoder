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
    vector<int> T(N);
    for(int i = 0; i < N; i++) cin >> T[i];

    int sum = 0;
    for(int i = 0; i < N; i++) sum += T[i];

    // お気持ち: 料理時間の部分和の最小値i -> max(i, sum - i)の最小値が答え
    // dp[i][j] := i番目のものからいくつか選んで和をjにできるか
    vector dp(N + 1, vector<int>(sum + 1));
    dp[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= sum; j++){
            if(j + T[i] <= sum) dp[i + 1][j + T[i]] |= dp[i][j];
            dp[i + 1][j] |= dp[i][j];
        }
    }

    int ans = sum;
    for(int i = 0; i <= sum; i++){
        if(dp[N][i]) ans = min(ans, max(i, sum - i));
    }

    cout << ans << endl;
}