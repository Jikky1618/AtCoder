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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), C(N), X(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < M; i++) cin >> X[i];

    // 絶対に買わないといけない商品 X
    vector<int> must(N + 1);
    for(int i = 0; i < M; i++){
        must[X[i] - 1] = true;
    }

    vector cost(N, vector<ll>(N));
    for(int i = 0; i < N; i++){
        ll val = INF;
        for(int j = i; j < N; j++){
            val = min(val, C[j]);
            cost[i][j] = val;
        }
    }

    // dp[i][j] := i番目まで買うかどうか決めたとき、買ったものがj個のときの最小値
    vector dp(N + 1, vector<ll>(N + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
        debug(i, j);
        if(!must[i]) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        if(0 <= i - j) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + A[i] + cost[i - j][i]);
        }
    }
    debug(dp);

    ll ans = *min_element(dp[N].begin(), dp[N].end());
    cout << ans << endl;
}