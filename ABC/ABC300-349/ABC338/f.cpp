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
template <class T>
bool warshall_floyd(vector<vector<pair<int, T>>>& G, vector<vector<T>>& dist) {
    int n = G.size();
    dist = vector(n, vector<T>(n, INF));
    for (int from = 0; from < n; from++) {
        for (auto [to, cost] : G[from]) {
            dist[from][to] = cost;
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int to = 0; to < n; to++) {
            for (int from = 0; from < n; from++) {
                if (dist[from][i] == INF || dist[i][to] == INF) continue;
                dist[from][to] =
                    min(dist[from][to], dist[from][i] + dist[i][to]);
            }
        }
    }

    // 負の閉路検知
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int U, V, W; cin >> U >> V >> W, U--, V--;
        G[U].emplace_back(V, W);
    }

    vector<vector<int>> dist;
    warshall_floyd(G, dist);

    // bit dp
    // dp[S][i] := 訪問した頂点の集合が S であり、現在位置が i のときの最小コスト
    vector dp(1 << N, vector<int>(N, INF));
    for(int i = 0; i < N; i++) dp[1 << i][i] = 0;

    for(int bit = 0; bit < (1 << N); bit++){
        for(int i = 0; i < N; i++){
            if(!((bit >> i) & 1) || (dp[bit][i] == INF)) continue;
            // 都市 j に移動
            for(int j = 0; j < N; j++){
                if(((bit >> j) & 1) || (dist[i][j] == INF)) continue;
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + dist[i][j]);
            }
        }
    }

    debug(dist, dp);
    int ans = INF;
    for(int i = 0; i < N; i++) ans = min(ans, dp[(1 << N) - 1][i]);

    if(ans == INF){
        cout << "No" << endl;
    }else{
        cout << ans << endl;
    }
}