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
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];

    // dp[i] := 足場 i にたどり着くまでに支払うコストの最小値
    // i is 0-indexed
    vector<int> dp(N, INF);
    dp[0] = 0;

    for(int i = 0; i < N; i++){
        // i + 1,..., i + K にジャンプ
        for(int nx = i + 1; nx <= i + K; nx++){
            if(nx < N) dp[nx] = min(dp[nx], dp[i] + abs(H[i] - H[nx]));
        }
    }

    cout << dp[N - 1] << endl;
}