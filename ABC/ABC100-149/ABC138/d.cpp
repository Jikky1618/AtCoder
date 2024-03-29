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
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b, a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    // dp[i] := 頂点 i のカウンターの数
    vector<int> dp(N); 
    while(Q--){
        int p, x; cin >> p >> x, p--;
        dp[p] += x;
    }

    // 根から順に dp を遷移
    auto dfs = [&](auto&& self, int pos, int par) -> void {
        for(auto np: G[pos]){
            if(np == par) continue;
            // pos の子に遷移
            dp[np] += dp[pos];
            self(self, np, pos);
        }
    };
    dfs(dfs, 0, -1);

    for(int i = 0; i < N; i++){
        cout << dp[i] << " \n"[i == N - 1];
    }
}