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
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++){
        int u, v, w; cin >> u >> v >> w, u--, v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto [np, cost]: G[pos]){
            if(dist[np] != -1) continue;
            dist[np] = dist[pos] + cost;
            que.push(np);
        }
    }
    
    vector<int> ans(N);
    for(int i = 0; i < N; i++){
        if(dist[i] % 2 == 0) ans[i] = 1;
    }

    for(int i = 0; i < N; i++) cout << ans[i] << "\n";
}