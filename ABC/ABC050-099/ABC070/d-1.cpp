#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

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
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++){
        int a, b, c; cin >> a >> b >> c, a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    int Q, K;
    cin >> Q >> K, K--;

    vector<ll> dist = dijkstra(G, K);

    while(Q--){
        int x, y; cin >> x >> y, x--, y--;
        ll ans = dist[x] + dist[y];
        cout << ans << "\n";
    }
}