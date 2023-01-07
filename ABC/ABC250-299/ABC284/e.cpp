#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<bool> seen(N, false);
    ll ans = 0, MAX = 1e6;

    auto dfs = [&](auto self, int pos) -> void {
        ans++;
        if(ans >= MAX){
            ans = MAX;
            return;
        }

        seen[pos] = true;
        for(auto &&np: G[pos]){
            if(seen[np] == true) continue;
            self(self, np);
        }
        seen[pos] = false;
    };

    dfs(dfs, 0);
    cout << ans << endl;
}