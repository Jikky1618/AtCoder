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
    int N, M;
    cin >> N >> M;
    vector dist(N, vector<ll>(N, INF));
    for(int i = 0; i < M; i++){
        int u, v, l; cin >> u >> v >> l, u--, v--;
        dist[u][v] = dist[v][u] = l;
    }
    
    for(int i = 0; i < N; i++) dist[i][i] = 0;

    for(int i = 1; i < N; i++){
        for(int to = 1; to < N; to++){
            for(int from = 1; from < N; from++){
                if(dist[from][i] == INF || dist[i][to] == INF) continue;
                dist[from][to] = min(dist[from][to], dist[from][i] + dist[i][to]);
            }
        }
    }

    ll ans = INF;
    for(int i = 1; i < N; i++){
        for(int j = i + 1; j < N; j++){
            ans = min(ans, dist[0][i] + dist[i][j] + dist[j][0]);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}