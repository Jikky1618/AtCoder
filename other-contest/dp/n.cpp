#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 累積和
    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    // dp[i][j] := 区間 [i, j) のスライムを纏めるときの最小コスト
    vector dp(N + 1, vector<ll>(N + 1, INF));
    // 初期値は A[i, i) = 0, A[i, i + 1) = 0
    for(int i = 0; i < N; i++) dp[i][i] = dp[i][i + 1] = 0;

    for(int len = 2; len <= N; len++){
        for(int left = 0; left + len <= N; left++){
            int right = left + len;
            for(int mid = left + 1; mid < right; mid++){
                // [left, mid) と [mid, right) を纏める
                ll cost = S[right] - S[mid] + S[mid] - S[left];
                dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid][right] + cost);
            }
        }
    }

    cout << dp[0][N] << endl;
}