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

    vector dp(N, vector<int>(N, -1));
    auto memo = [&](auto &&self, int l, int r) -> int {
        if(l >= r) return dp[l][r] = 0;
        if(dp[l][r] != -1) return dp[l][r];

        dp[l][r] = 0;
        int p1 = (l + 1 <= P[l] && P[l] <= r ? A[l] : 0);
        int p2 = (l <= P[r] && P[r] <= r - 1 ? A[r] : 0);
        dp[l][r] = max(self(self, l + 1, r) + p1, self(self, l, r - 1) + p2);

        return dp[l][r];
    };

    memo(memo, 0, N - 1);
    debug(dp);
    cout << dp[0][N - 1] << endl;
}