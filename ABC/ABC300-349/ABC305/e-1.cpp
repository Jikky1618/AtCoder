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
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b, a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    vector<int> dist(N, -1);
    priority_queue<pair<int, int>> que;
    for(int i = 0; i < K; i++){
        int p, h; cin >> p >> h, p--;
        que.emplace(h, p);
        dist[p] = h;
    }

    while(!que.empty()){
        auto [h, p] = que.top(); que.pop();
        if(h == 0) continue;
        for(auto np: G[p]){
            if(dist[np] < dist[p] - 1){
                dist[np] = dist[p] - 1;
                que.emplace(dist[np], np);
            }
        }
    }

    debug(dist);
    vector<int> ans;
    for(int i = 0; i < N; i++) if(dist[i] != -1) ans.emplace_back(i + 1);

    int cnt = ans.size();
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++){
        cout << ans[i] << " \n"[i == cnt - 1];
    }
}