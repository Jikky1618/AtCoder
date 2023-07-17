#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;
template <class T>
vector<double> dijkstra(const vector<vector<pair<int, T>>> &G, int start = 0) {
    int n = G.size();
    vector<double> dist(n, INF);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    dist[start] = 0;
    que.emplace(dist[start], start);
    while (!que.empty()) {
        auto [expected, from] = que.top();
        que.pop();
        if (dist[from] < expected) continue;  // 最短距離でなければ無視
        for (auto [to, cost] : G[from]) {
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                que.emplace(dist[to], to);
            }
        }
    }
    return dist;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    int N;
    cin >> N;
    vector<int> x(N), y(N), r(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> r[i];

    // バリアの中心 + {sx, sy} + {gx, gy} でグラフを作る
    vector<vector<pair<int, double>>> G(N + 2);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            // 中心距離から 2 つのバリアの大きさを引いた距離が宇宙線を浴びる距離
            double dist = max(hypot(abs(x[i] - x[j]), abs(y[i] - y[j])) - r[i] - r[j], 0.0);
            G[i + 1].emplace_back(j + 1, dist);
            G[j + 1].emplace_back(i + 1, dist);
        }
    }
    // スタート-バリア間, バリア-ゴール間も辺を追加
    for(int i = 0; i < N; i++){
        double dist1 = max(hypot(abs(sx - x[i]), abs(sy - y[i])) - r[i], 0.0);
        double dist2 = max(hypot(abs(gx - x[i]), abs(gy - y[i])) - r[i], 0.0);
        G[0].emplace_back(i + 1, dist1);
        G[i + 1].emplace_back(0, dist1);
        G[N + 1].emplace_back(i + 1, dist2);
        G[i + 1].emplace_back(N + 1, dist2);
    }
    // スタート-ゴール間も辺を追加
    {
        ll dist = hypot(abs(sx - gx), abs(sy - gy));
        G[0].emplace_back(N + 1, dist);
        G[N + 1].emplace_back(0, dist);
    }

    auto dist = dijkstra(G);
    debug(dist);
    cout << dist[N + 1] << endl;
}