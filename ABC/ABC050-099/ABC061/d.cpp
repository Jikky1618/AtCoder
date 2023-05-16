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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int A, B, C; cin >> A >> B >> C, A--, B--;
        // 最大経路 -> 辺の長さを-1倍して最短経路
        G[A].emplace_back(B, -C);
    }

    // ベルマンフォード法
    vector<ll> dist(N, INF);
    dist[0] = 0;
    for(int i = 0; i < N; i++){
        for(int from = 0; from < N; from++){
            if(dist[from] == INF) continue;
            for(auto [to, cost]: G[from]){
                if(dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                }
            }
        }
    }

    // もう N 回更新を行って, 更新されたら, その頂点は負の閉路を含む
    vector<bool> negative_loop(N);
    for(int i = 0; i < N; i++){
        for(int from = 0; from < N; from++){
            if(dist[from] == INF) continue;
            for(auto [to, cost]: G[from]){
                if(dist[to] > dist[from] + cost){
                    negative_loop[to] = true;
                    dist[to] = dist[from] + cost;
                }
            }
        }
    }

    if(negative_loop[N - 1]){
        cout << "inf" << endl;
    }else{
        cout << -dist[N - 1] << endl;
    }
}