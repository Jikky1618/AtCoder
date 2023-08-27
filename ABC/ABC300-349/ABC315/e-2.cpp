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
    for(int i = 0; i < N; i++){
        int C; cin >> C;
        for(int j = 0; j < C; j++){
            int p; cin >> p, p--;
            G[i].emplace_back(p);
        }
    }

    vector<int> ans;
    vector<int> seen(N);
    // DFS で帰り替え順を記録 (トポロジカルソート)
    auto dfs = [&](auto&& self, int pos) -> void {
        seen[pos] = true;
        for(auto np: G[pos]){
            if(seen[np]) continue;
            self(self, np);
        }
        ans.emplace_back(pos);
    };
    dfs(dfs, 0);
    
    int M = ans.size() - 1;
    for(int i = 0; i < M; i++){
        cout << ans[i] + 1 << " \n"[i == M - 1];
    }
}