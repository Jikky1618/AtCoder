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
    int H, W;
    cin >> H >> W;
    vector c(10, vector<int>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) cin >> c[i][j];
    }
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }

    // グラフに変える
    vector<vector<pair<int, int>>> G(10);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            G[i].emplace_back(j, c[i][j]);
        }
    }

    vector<int> dist(10);
    for(int i = 0; i < 10; i++){
        auto d = dijkstra(G, i);
        dist[i] = d[1];
    }

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == -1 || A[i][j] == 1) continue;
            ans += dist[A[i][j]];
        }
    }

    cout << ans << endl;
}