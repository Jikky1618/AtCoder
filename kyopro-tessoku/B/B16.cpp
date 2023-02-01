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
    vector<int> h(N);
    for(int i = 0; i < N; i++) cin >> h[i];

    // dp[i] := 足場iにたどり着くまでに支払うコスト(配るdp)
    vector dp(N, INF);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        if(i + 1 < N) dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        if(i + 2 < N) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
    }

    cout << dp[N - 1] << endl;
}