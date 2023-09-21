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
    int N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];

    // M := 価値の上限
    int M = N * 1000;
    // dp[i][j] := i 番目以前まで選んだとき, 価値が j になる重さの最小値
    vector dp(N + 1, vector<ll>(M + 1, INF));
    dp[0][0] = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            // i 番目を選ぶとき
            if(j + v[i] <= M) dp[i + 1][j + v[i]] = min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
            // i 番目を選ばないとき
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }

    ll ans = 0;
    // 重さが W 以下を達成できるなら価値 i を達成できる
    for(int i = 0; i <= M; i++){
        if(dp[N][i] <= W) ans = i;
    }

    cout << ans << endl;
}