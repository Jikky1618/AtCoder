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
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int x, y; cin >> x >> y, x--, y--;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    vector<int> dist(N);
    // ダブリング
    // dp[k][i] := 頂点 i の 2^k 個上の親
    int LOG =1;
    while((1 << LOG) < N) LOG++;
    vector dp(LOG, vector<int>(N, -1));
    // 初期値は dfs で求める
    auto dfs = [&](auto&& self, int pos, int parent) -> void {
        dp[0][pos] = parent; // 2^0 個上の親
        for(auto np: G[pos]){
            if(np == parent) continue;
            dist[np] = dist[pos] + 1;
            self(self, np, pos);
        }
    };

    dfs(dfs, 0, -1);
    debug(dp[0]);
    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < N; i++){
            if(dp[k][i] == -1){
                dp[k + 1][i] = dp[k][i];
            }else{
                dp[k + 1][i] = dp[k][dp[k][i]];
            }
        }
    }

    debug(dp.size(), LOG);

    // level ancestor
    auto LA = [&](int pos, int d) -> int {
        for(int i = 0; i < LOG; i++){
            if((d >> i) & 1){
                pos = dp[i][pos];
            }
        }
        return pos;
    };

    auto LCA = [&](int x, int y) -> int {
        if(dist[x] < dist[y]) swap(x, y); // x の方が深い頂点とする
        // x の高さを y と同じ高さにする
        x = LA(x, dist[x] - dist[y]);
        if(x == y) return x;
        // LCA の直前をダブリングを用いて二分探索
        for(int i = LOG - 1; i >= 0; i--){
            if(dp[i][x] != dp[i][y]){
                x = dp[i][x];
                y = dp[i][y];
            }   
        }
        return dp[0][x];
    };

    int Q;
    cin >> Q;
    while(Q--){
        int a, b; cin >> a >> b, a--, b--;
        int L = LCA(a, b);
        // a-b 間にパスを繋いだとき, サイクルの長さを求める
        int ans = (dist[a] - dist[L]) + (dist[b] - dist[L]) + 1;
        cout << ans << '\n';
    }
}