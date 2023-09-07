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
    vector<int> a(N), b(N);
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        cin >> a[i] >> b[i], a[i]--, b[i]--;
        G[a[i]].emplace_back(b[i]);
        G[b[i]].emplace_back(a[i]);
    }
    int Q;
    cin >> Q;

    // それぞれの頂点の深さを調べる
    vector<int> depth(N);
    auto dfs = [&](auto&& self, int pos, int par) -> void {
        for(auto np: G[pos]){
            if(np == par) continue;
            depth[np] = depth[pos] + 1;
            self(self, np, pos);
        }
    };
    dfs(dfs, 0, -1);

    debug(depth);

    vector<ll> dp(N);
    while(Q--){
        int t, e, x; cin >> t >> e >> x, e--;

        if(t == 1){
            // a[e] が親のとき
            if(depth[a[e]] < depth[b[e]]){
                dp[0] += x;
                dp[b[e]] -= x;
            // b[e] が親のとき
            }else{
                dp[a[e]] += x;
            }
        }
        if(t == 2){
            // a[e] が親のとき
            if(depth[a[e]] < depth[b[e]]){
                dp[b[e]] += x;
            // b[e] が親のとき
            }else{
                dp[0] += x;
                dp[a[e]] -= x;
            }
        }
    }

    // 根から順に dp を遷移
    auto dfs2 = [&](auto&& self, int pos, int par) -> void {
        for(auto np: G[pos]){
            if(np == par) continue;
            dp[np] += dp[pos];
            self(self, np, pos);
        }
    };
    dfs2(dfs2, 0, -1);

    for(int i = 0; i < N; i++){
        cout << dp[i] << '\n';
    }
}