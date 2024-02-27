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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    ll ans = 1;
    vector<bool> seen(N);
    for(int i = 0; i < N; i++){
        if(seen[i]) continue;
        seen[i] = true;

        // 頂点 i との連結成分を求める
        // group は行きがけ順で頂点番号を入れないといけない
        vector<int> group;
        auto dfs = [&](auto&& self, int pos) -> void {
            group.emplace_back(pos);
            for(auto&& to : G[pos]){
                if(seen[to]) continue;
                seen[to] = true;
                self(self, to);
            }
        };
        dfs(dfs, i);

        // val := 連結成分 group の色の塗り方
        ll val = 0;
        vector<int> color(N, -1);
        auto dfs2 = [&](auto&& self, int pos) -> void {
            if(pos == int(group.size())){
                val++;
                return;
            }
            // flag[c] := 頂点 group[pos] の隣接頂点で色 c が使われているか
            vector<bool> flag(3);
            for(auto&& to: G[group[pos]]){
                if(color[to] != -1) flag[color[to]] = true;
            }
            for(int nc = 0; nc < 3; nc++){
                if(flag[nc]) continue;
                color[group[pos]] = nc;
                self(self, pos + 1);
                color[group[pos]] = -1;
            }
        };
        dfs2(dfs2, 0);
        ans *= val;
    }

    cout << ans << '\n';
}