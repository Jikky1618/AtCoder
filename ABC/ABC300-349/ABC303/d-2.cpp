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
    int X, Y, Z;
    string S;
    cin >> X >> Y >> Z >> S;

    int N = S.size();
    vector<vector<pair<int, ll>>> G(2 * N);

    for(int i = 0; i < N; i++){
        if(S[i + 1] == 'a'){
            G[i].emplace_back(i + 1, X);
            G[i + N].emplace_back(i + N + 1, Y);
        }else if(S[i + 1] == 'A'){
            G[i].emplace_back(i + 1, Y);
            G[i + N].emplace_back(i + N + 1, X);
        }
        G[i].emplace_back(i + N, Z);
        G[i + N].emplace_back(i, Z);
    }

    auto dist = dijkstra(G);
    ll val = min(dist[N - 1], dist[2 * N - 1]) + (S[0] == 'a' ? X : Y);
    auto dist2 = dijkstra(G, N);
    ll val2 = min(dist2[N - 1], dist2[2 * N - 1]) + Z + (S[0] == 'a' ? Y : X);

    ll ans = min(val, val2);
    cout << ans << endl;
}