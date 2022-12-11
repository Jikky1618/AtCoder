#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

struct Edge{
    int to; // 辺の終点
    int weight; // 辺の重み
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for(int i = 0; i < M; i++){
        int A, B, C; cin >> A >> B >> C; A--, B--;
        G[A].push_back({B, C});
        G[B].push_back({A, C});
    }

    vector<int> dist(N, INF); // dist[i]: 頂点iの暫定的な距離
    vector<bool> done(N, false); // done[i]: 頂点iの最短距離が確定しているか
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    pq.push({dist[0], 0});

    while(!pq.empty()){
        int pos = pq.top().second; pq.pop();
        // 既に確定していたら、continue
        if(done[pos] == true) continue;

        done[pos] = true;
        for(auto next_pos: G[pos]){
            int np = next_pos.to;
            int w = next_pos.weight;
            if(dist[np] > dist[pos] + w){
                dist[np] = dist[pos] + w;
                pq.push({dist[np], np});
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}