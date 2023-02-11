#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        vector<int> C(N);
        for(int i = 0; i < N; i++) cin >> C[i];
        vector<vector<int>> G(N);
        for(int i = 0; i < M; i++){
            int u, v; cin >> u >> v; u--, v--;
            G[u].push_back(v), G[v].push_back(u);
        }

        vector dist(N, vector<int>(N, -1));
        queue<pair<int, int>> que;

        dist[0][N - 1] = 0;
        que.push({0, N - 1});

        while(!que.empty()){
            auto pos = que.front(); que.pop();
            for(auto nx: G[pos.first]){
                for(auto ny: G[pos.second]){
                    if(dist[nx][ny] != -1) continue;
                    if(C[nx] == C[ny]) continue;
                    dist[nx][ny] = dist[pos.first][pos.second] + 1;
                    que.push({nx, ny});
                }
            }
        }
        cout << dist[N - 1][0]  << '\n';
    }
}