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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, ll>>> G(N);
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c, a--, b--;
        G[a].emplace_back(b, c);
    }

    for(int i = 0; i < N; i++){
        ll ans = INF;
        // dijkstra
        vector<ll> dist(N, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
        dist[i] = 0;
        que.emplace(dist[i], i);
        while(!que.empty()){
            auto [expected, from] = que.top();
            que.pop();
            if(dist[from] < expected) continue;  // 最短距離でなければ無視
            for(auto [to, cost]: G[from]){
                // 町 i に戻ってくる場合
                if(to == i){
                    ans = min(ans, dist[from] + cost);
                }
                // to の距離更新
                if(dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                    que.emplace(dist[to], to);
                }
            }
        }
        
        cout << (ans == INF ? -1 : ans) << '\n';
    }
}