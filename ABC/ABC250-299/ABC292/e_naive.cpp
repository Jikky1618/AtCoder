#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector G(N, vector<int>(N, INF));
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v, u--, v--;
        G[u][v] = 1;
    }

    for(int i = 0; i < N; i++) G[i][i] = 0;

    ll cnt = 0;
    // ワーシャルフロイド
    for(int i = 0; i < N; i++){
        for(int to = 0; to < N; to++){
            if(G[i][to] == INF) continue; // 早めに打ち切る
            for(int from = 0; from < N; from++){
                if(G[from][i] == INF) continue;
                if(G[from][to] == INF){
                    G[from][to] = 1;
                    cnt++;
                }
            }
        }
    }

    cout << cnt << '\n';
}