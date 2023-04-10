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
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int A, B, C; cin >> A >> B >> C, A--, B--;
        G[A].emplace_back(B, C);
        G[B].emplace_back(A, C);
    }

    auto dist1 = dijkstra(G); // 頂点1からの最短距離
    auto dist2 = dijkstra(G, N - 1); // 頂点Nからの最短距離

    for(int i = 0; i < N; i++){
        int ans = dist1[i] + dist2[i];
        cout << ans << "\n";
    }
}