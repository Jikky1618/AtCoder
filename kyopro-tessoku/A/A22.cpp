#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    vector<int> A(N - 1), B(N - 1);
    for(int i = 0; i < N - 1; i++) cin >> A[i], A[i]--;
    for(int i = 0; i < N - 1; i++) cin >> B[i], B[i]--;

    // dp[i] := マスiにたどり着いたとき合計スコアの最大値
    vector<int> dp(N, -INF);
    dp[0] = 0;
    for(int i = 0; i < N - 1; i++){
        dp[A[i]] = max(dp[A[i]], dp[i] + 100);
        dp[B[i]] = max(dp[B[i]], dp[i] + 150);
    }

    debug(dp);
    cout << dp[N - 1] << endl;
}