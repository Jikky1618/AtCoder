#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

struct Edge {
    int to; // 辺の終点
    int cost; // 辺の重み
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    // グラフの入力
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for(int i = 0; i < M; i++){
        int A, B, C; cin >> A >> B >> C, A--, B--;
        G[A].push_back({B, C});
        G[B].push_back({A, C});
    }

    vector<int> dist(N, INF); // dist[i]: 頂点iの暫定距離
    vector<bool> done(N, false); // done[i]: 頂点iの距離は確定したか
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 初期化
    dist[0] = 0;
    pq.push({dist[0], 0}); // val, pos

    // ダイクストラ法
    while(!pq.empty()){
        auto [val, pos] = pq.top(); pq.pop();
        if(done[pos] == true) continue; // 距離が確定していたらcontinue
        for(auto np: G[pos]){
            // もし、distに更新があるなら
            if(dist[np.to] > dist[pos] + np.cost){
                dist[np.to] = dist[pos] + np.cost;
                pq.push({dist[np.to], np.to});
            }
        }
        done[pos] = true; // dist[pos]を確定させる
    }

    for(int i = 0; i < N; i++){
        cout << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}