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
        int a, b; cin >> a >> b, a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    int Q; cin >> Q;
    while(Q--){
        int x, k; cin >> x >> k, x--;
        // map で距離を管理
        unordered_map<int, int> dist;
        queue<int> que;
        dist[x] = 0;
        que.emplace(x);
        while(!que.empty()){
            int pos = que.front(); que.pop();
            for(auto&& np : G[pos]){
                // 既に訪問済みなら continue
                if(dist.count(np)) continue;
                // 距離が k を超えていたら枝刈り
                if(dist[pos] + 1 > k) continue;
                dist[np] = dist[pos] + 1;
                que.emplace(np);
            }
        }

        int ans = 0;
        // 訪れた頂点集合の番号の総和を取る
        for(auto [key, val]: dist) ans += key + 1;
        cout << ans << '\n';
    }
}