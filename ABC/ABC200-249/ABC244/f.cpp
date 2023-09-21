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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    // dp[S][i] := i 番目の頂点を通ったとき, 頂点集合 S を通るパスの最短距離
    vector dp(1 << N, vector<int>(N, INF));
    queue<pair<int, int>> que;
    for(int i = 0; i < N; i++){
        dp[1 << i][i] = 1;
        que.emplace(1 << i, i);
    }

    while(!que.empty()){
        auto [bit, pos] = que.front();
        que.pop();
        for(auto np: G[pos]){
            // nx 番目の bit を flip する
            int nbit = bit ^ (1 << np);
            if(dp[nbit][np] == INF){
                dp[nbit][np] = dp[bit][pos] + 1;
                que.emplace(nbit, np);
            }
        }
    }

    int ans = 0;
    for(int bit = 1; bit < (1 << N); bit++){
        int dist = *min_element(dp[bit].begin(), dp[bit].end());
        ans += (dist == INF ? 0 : dist);
    }

    cout << ans << endl;
}