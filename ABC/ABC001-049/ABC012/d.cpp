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
    vector G(N, vector<int>(N, INF));
    for(int i = 0; i < M; i++){
        int a, b, t; cin >> a >> b >> t, a--, b--;
        G[a][b] = G[b][a] = t;
    }
    
    for(int i = 0; i < N; i++) G[i][i] = 0;

    // ワーシャルフロイド法
    for(int i = 0; i < N; i++){
        for(int to = 0; to < N; to++){
            for(int from = 0; from < N; from++){
                if(G[from][i] == INF || G[i][to] == INF) continue;
                G[from][to] = min(G[from][to], G[from][i] + G[i][to]);
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < N; i++){
        ans = min(ans, *max_element(G[i].begin(), G[i].end()));
    }

    cout << ans << endl;
}