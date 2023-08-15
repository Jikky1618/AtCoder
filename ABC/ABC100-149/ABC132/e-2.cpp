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
    // 3 倍加頂点したグラフを用意
    vector<vector<int>> G(3 * N);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(N + v);
        G[N + u].emplace_back(2 * N + v);
        G[2 * N + u].emplace_back(v);
    }
    int S, T;
    cin >> S >> T, S--, T--;

    vector<int> dist(3 * N, -1);
    queue<int> que;
    dist[S] = 0;
    que.emplace(S);
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(auto np: G[pos]){
            if(dist[np] != -1) continue;
            dist[np] = dist[pos] + 1;
            que.emplace(np);
        }
    }
    
    cout << (dist[T] == -1 ? -1 : dist[T] / 3) << endl;
}