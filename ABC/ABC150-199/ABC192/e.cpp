#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

template<class T, class U>
T floor(T x, U y){
    return (x ? x / y : (x + y - 1) / y);
}
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, X, Y;
    cin >> N >> M >> X >> Y, X--, Y--;
    vector<vector<tuple<int, int, ll>>> G(N);
    vector<int> K(M);
    for(int i = 0; i < M; i++){
        int A, B, T; cin >> A >> B >> T >> K[i], A--, B--;
        G[A].emplace_back(i, B, T);
        G[B].emplace_back(i, A, T);
    }
    debug(G);

    // dijkstra
    vector<ll> dist(N, INF);
    dist[X] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, X);

    while(!que.empty()){
        auto [t, from] = que.top(); que.pop();
        if(dist[from] < t) continue;
        for(auto [id, to, cost]: G[from]){
            ll next = ceil(dist[from], K[id]) * K[id];
            if(dist[to] > next + cost){
                dist[to] = next + cost;
                que.emplace(dist[to], to);
            }
        }
    }

    cout << (dist[Y] == INF ? -1 : dist[Y]) << endl;
}