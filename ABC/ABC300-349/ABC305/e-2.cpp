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
    vector<vector<int>> G(N * 2 + 1);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b, a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    // 超頂点を作成
    // ref. https://twitter.com/leaf_1415/status/1667531694507974656
    for(int i = 0; i < K; i++){
        int p, h; cin >> p >> h, p--;
        G[N + h].emplace_back(p);
    }
    // 超頂点間に辺を貼る
    for(int i = 1; i < N; i++){
        G[N + i + 1].emplace_back(N + i);
    }

    debug(G);
    vector<int> dist(2 * N + 1, INF);
    queue<int> que;
    dist[N + N] = 0;
    que.emplace(N + N);

    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(dist[np] != INF) continue;
            dist[np] = dist[pos] + 1;
            que.emplace(np);
        }
    }

    debug(dist);
    vector<int> ans;
    for(int i = 0; i < N; i++) if(dist[i] <= N + 1) ans.emplace_back(i + 1);

    int cnt = ans.size();
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++){
        cout << ans[i] << " \n"[i == cnt - 1];
    }
}