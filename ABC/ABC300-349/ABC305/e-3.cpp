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
    vector<vector<pair<int, int>>> G(N + 1);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b, a--, b--;
        G[a].emplace_back(b, 1);
        G[b].emplace_back(a, 1);
    }

    // 「警備室」の超頂点を作成
    // ref. https://twitter.com/kyopro_friends/status/1667530762693021705
    for(int i = 0; i < K; i++){
        int p, h; cin >> p >> h, p--;
        // 警備室(頂点 N)から頂点 p に長さ N - h の辺を貼る
        G[N].emplace_back(p, N - h);
    }

    vector<int> dist(N + 1, INF);
    // {cost, pos}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    dist[N] = 0;
    que.emplace(0, N);
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

    vector<int> ans;
    for(int i = 0; i < N; i++) if(dist[i] <= N) ans.emplace_back(i + 1);

    int cnt = ans.size();
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++){
        cout << ans[i] << " \n"[i == cnt - 1];
    }
}