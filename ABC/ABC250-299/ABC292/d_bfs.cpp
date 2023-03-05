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
        int u, v; cin >> u >> v, u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> dist(N, -1);

    bool flag = true;
    for(int i = 0; i < N; i++){
        if(dist[i] != -1) continue;

        dist[i] = 0;
        queue<int> que;
        que.push(i);

        ll edge = 0, vertex = 1; // 辺の本数, 頂点の個数
        while(!que.empty()){
            int pos = que.front(); que.pop();
            for(auto np: G[pos]){
                edge++;
                if(dist[np] != -1) continue;
                dist[np] = dist[pos] + 1;
                que.push(np);
                vertex++;
            }
        }
        debug(edge, vertex);
        if(edge != vertex * 2) flag = false;
    }

    cout << (flag ? "Yes" : "No") << endl;
    debug(dist);
}