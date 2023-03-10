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
    // G[i] := 頂点iの{隣接頂点, 辺番号}
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b, a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    vector<int> col(N - 1);
    // pos: 現在位置, p: 親の頂点番号, pc: 親から来た辺の色
    auto dfs = [&](auto &&self, int pos, int p = -1, int pc = -1) -> void {
        int color = 1;
        if(color == pc) color++;
        for(auto np: G[pos]){
            if(np.first == p) continue;
            col[np.second] = color;
            self(self, np.first, pos, col[np.second]);
            color++;
            if(color == pc) color++;
        }
    };

    dfs(dfs, 0);

    cout << *max_element(col.begin(), col.end()) << endl;
    for(int i = 0; i < N - 1; i++) cout << col[i] << endl;
}