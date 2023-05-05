#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int X, Y; cin >> X >> Y, X--, Y--;
        G[X].emplace_back(Y);
    }

    // dp[i] := 頂点iから到達できる頂点で最小値
    vector<ll> dp(N, INF);
    for(int i = 0; i < N; i++){
        for(auto j: G[i]){
            dp[j] = min({dp[j], dp[i], A[i]});
        }
    }
    debug(val);
    ll ans = -INF;
    for(int i = 0; i < N; i++) ans = max(ans, A[i] - dp[i]);

    cout << ans << endl;
}