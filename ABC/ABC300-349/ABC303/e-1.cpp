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
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(v), G[v].emplace_back(u);
    }

    vector<int> seen(N), ans;
    // Lv 3 以上の頂点を全て探索
    for(int i = 0; i < N; i++){
        if(G[i].size() >= 3){
            ans.emplace_back(G[i].size());
            seen[i] = true;
            // 頂点 i から伸びている頂点は全て star の一部
            for(auto np: G[i]){
                seen[np] = true;
            }
        }
    }

    // Lv 2 の頂点を探す
    int cnt = 0;
    for(int i = 0; i < N; i++) if(!seen[i]) cnt++;
    for(int i = 0; i < cnt / 3; i++) ans.emplace_back(2);

    sort(ans.begin(), ans.end());
    int M = ans.size();
    for(int i = 0; i < M; i++){
        cout << ans[i] << " \n"[i == M - 1];
    }
}