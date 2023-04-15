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
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int Q;
    cin >> Q;

    while(Q--){
        int x, k; cin >> x >> k, x--;

        // 枝刈りBFSをしてみる
        map<int, int> dist;
        queue<int> que;

        dist[x] = 0;
        que.emplace(x);

        ll ans = 0;
        while(!que.empty()){
            int pos = que.front(); que.pop();
            ans += (pos + 1);
            
            if(dist[pos] == k) continue;

            for(auto np: G[pos]){
                if(dist.count(np)) continue;
                dist[np] = dist[pos] + 1;
                que.emplace(np);
            }
        }

        cout << ans << "\n";
    }
}