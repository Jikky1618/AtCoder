#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll Ans = N * (N - 1) / 2 - M; 
    bool is_bipartite = true; // 二部グラフかどうか
    
    vector<int> dist(N, -1);
    queue<int> que;
    for(int i = 0; i < N; i++){
        if(dist[i] != -1) continue;
        ll B = 0, W = 0; // 黒のマス数: B, 白のマス数: W
        dist[i] = 0; que.push(i);
        while(!que.empty()){
            int p = que.front(); que.pop();
            if(dist[p] % 2 == 0) B++;
            if(dist[p] % 2 == 1) W++;

            for(auto np: G[p]){
                if(dist[np] == -1){
                    dist[np] = dist[p] + 1;
                    que.push(np);
                }else{
                    if(dist[p] == dist[np]) is_bipartite = false;
                }
            }
        }
        Ans -= B * (B - 1) / 2;
        Ans -= W * (W - 1) / 2;
    }

    // 二部グラフではないなら 0
    if(is_bipartite) cout << Ans << endl;
    else cout << 0 << endl;

    return 0;
}