#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> G(2 * N);
    for(int i = 0; i < M; i++){
        int u, v, c; cin >> u >> v >> c, u--, v--;
        if(c == 1) G[u].push_back({v, 1}), G[v].push_back({u, 1});
        else G[u + N].push_back({v + N, 1}), G[v + N].push_back({u + N, 1});
    }
    for(int i = 0; i < K; i++){
        int s; cin >> s, s--;
        G[s + N].push_back({s, 0}), G[s].push_back({s + N, 0});
    }

    // 01-BFS
    deque<int> deq;
    vector<int> dist(2 * N, INF);

    deq.push_back(0);
    dist[0] = 0;

    while(!deq.empty()){
        int pos = deq.front(); deq.pop_front();
        for(auto [to, cost]: G[pos]){
            if(dist[to] > dist[pos] + cost){
                dist[to] = dist[pos] + cost;
                if(cost == 0) deq.push_front(to);
                else deq.push_back(to);
            }
        }
    }

    int ans = min(dist[N - 1], dist[2 * N - 1]);
    cout << (ans == INF ? -1 : ans) << endl;
}