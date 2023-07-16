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
template<class T>
vector<ll> dijkstra(const vector<vector<pair<int, T>>> &G, int start = 0){
    int n = G.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    dist[start] = 0;
    que.emplace(dist[start], start);
    while(!que.empty()){
        auto [expected, from] = que.top(); que.pop();
        if(dist[from] < expected) continue; // 最短距離でなければ無視
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
    vector<ll> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];

    vector<vector<pair<int, ll>>> G(N);
    for(int i = 0; i < M; i++){
        int U, V; cin >> U >> V, U--, V--;
        // 「楽しさが増える量は、標高が減った量と同じである」ことに着目
        // 「楽しさ + 標高」の -1 倍をグラフの辺の重みとする
        // H[U] > H[V] のとき
        // U -> V には コスト 0 (楽しさ + 標高 = 0)
        // V -> U には コスト H[U] - H[V] をかける (楽しさ + 標高 = H[V] - H[U] の -1 倍)
        if(H[U] > H[V]){
            G[U].emplace_back(V, 0);
            G[V].emplace_back(U, H[U] - H[V]);
        }else{
            G[V].emplace_back(U, 0);
            G[U].emplace_back(V, H[V] - H[U]);
        }
    }

    // dijkstra で 「楽しさ + 標高」の最大値(正確にはその -1 倍)を求める
    auto dist = dijkstra(G);
    debug(dist);
    ll ans = -INF;
    // 楽しさ = 標高 - dist(楽しさ + 標高の -1 倍)
    for(int i = 0; i < N; i++) ans = max(ans, H[0] - H[i] - dist[i]);

    cout << ans << endl;
}