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
vector<ll> bellman_ford(vector<vector<pair<int, T>>>& G, int start = 0){
    int n = G.size();
    vector<ll> dist(n, INF);
    dist[start] = 0;
    // 最低でも n 回はループを回して, 頂点の最短距離を更新する
    // 負の閉路があればもう n 回ループを回して, 負の閉路がある頂点を更新する
    for(int i = 0; i < 2 * n; i++){
        bool updated = false;
        for(int from = 0; from < n; from++){
            if(dist[from] == INF) continue;
            for(auto [to, cost]: G[from]){
                if(dist[to] > dist[from] + cost){
                    updated = true;
                    if(i < n){
                        dist[to] = dist[from] + cost;
                    }else{
                        dist[to] = -INF;
                    }
                }
            }
        }
        // 距離の更新が行われなかったらもう更新する頂点はない
        if(!updated){
            return dist;
        }
    }
    return dist;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, P;
    cin >> N >> M >> P;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int A, B, C; cin >> A >> B >> C, A--, B--;
        // 最大スコア -> -1倍して最小スコア
        G[A].emplace_back(B, -(C - P));
    }

    auto dist = bellman_ford(G);

    ll ans = -dist[N - 1];
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << max(0LL, ans) << endl;
    }
}