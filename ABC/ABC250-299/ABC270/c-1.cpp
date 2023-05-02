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
    int N, X, Y;
    cin >> N >> X >> Y, X--, Y--;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int U, V; cin >> U >> V, U--, V--;
        G[U].emplace_back(V);
        G[V].emplace_back(U);
    }

    vector<int> path{X};
    auto dfs = [&](auto&& self, int pos, int p) -> void {
        if(pos == Y){
            int m = path.size();
            for(int i = 0; i < m; i++){
                cout << path[i] + 1 << " \n"[i == m - 1];
            }
            return;
        }
        for(auto np: G[pos]){
            if(np == p) continue;
            path.emplace_back(np);
            self(self, np, pos);
            path.pop_back();
        }
    };

    dfs(dfs, X, -1);
}