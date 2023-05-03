#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int id = 1;
    vector<int> leaf(N);
    // 全ての葉にidを付与
    auto dfs = [&](auto&& self, int pos, int p) -> void {
        if(pos != 0 && G[pos].size() == 1){
            leaf[pos] = id, id++;
            return;
        }
        for(auto np: G[pos]){
            if(np == p) continue;
            self(self, np, pos);
        }
    };

    dfs(dfs, 0, -1);
    debug(leaf);
    
    // L, Rの更新作業
    vector<int> L(N), R(N);
    auto dfs2 = [&](auto&& self, int pos, int p) -> void {
        if(leaf[pos]){
            L[pos] = R[pos] = leaf[pos];
            return;
        }
        L[pos] = INF, R[pos] = -INF;
        for(auto np: G[pos]){
            if(np == p) continue;
            self(self, np, pos);
            L[pos] = min(L[pos], L[np]);
            R[pos] = max(R[pos], R[np]);
        }
    };

    dfs2(dfs2, 0, -1);
    debug(L, R);

    for(int i = 0; i < N; i++){
        cout << L[i] << " " << R[i] << "\n";
    }
}