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
    for(int i = 1; i < N; i++){
        int P; cin >> P, P--;
        G[P].emplace_back(i);
    }

    debug(G);
    int timer = 0;
    vector<int> in(N), out(N), dist(N);
    vector<vector<int>> list(N);
    auto dfs = [&](auto&& self, int pos, int par) -> void {
        in[pos] = timer++;
        list[dist[pos]].emplace_back(in[pos]);
        for(auto np: G[pos]){
            if(np == par) continue;
            dist[np] = dist[pos] + 1;
            self(self, np, pos);
        }
        out[pos] = timer++;
    };
    dfs(dfs, 0, -1);
    debug(in, out, dist, list);

    int Q;
    cin >> Q;
    while(Q--){
        int U, D; cin >> U >> D, U--;
        int ans = lower_bound(list[D].begin(), list[D].end(), out[U]) - lower_bound(list[D].begin(), list[D].end(), in[U]);
        cout << ans << '\n';
    }
}