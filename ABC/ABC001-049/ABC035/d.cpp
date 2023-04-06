#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int INF = (1 << 30) - 1;
template<class T>
vector<ll> dijkstra(const vector<vector<pair<int, T>>> &G, int start = 0){
    int n = G.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    dist[start] = 0;
    que.emplace(0, start);
    while(!que.empty()){
        auto [d, from] = que.top(); que.pop();
        if(dist[from] < d) continue; // 最短距離でなければ無視
        for(auto [to, cost]: G[from]){
            if(dist[to] > dist[from] + cost){
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
    int N, M, T;
    cin >> N >> M >> T;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<vector<pair<int, int>>> G(N), rG(N); // rG: Gの辺の向きを逆にしたグラフ
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c, a--, b--;
        G[a].emplace_back(b, c);
        rG[b].emplace_back(a, c);
    }

    auto dist1 = dijkstra(G);
    auto dist2 = dijkstra(rG);
    debug(dist1, dist2);

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ll val = (T - dist1[i] - dist2[i]) * A[i];
        ans = max(ans, val);
    }

    cout << ans << endl;
}