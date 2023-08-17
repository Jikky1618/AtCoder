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

template <class T>
bool warsahll_floyd(vector<vector<pair<int, T>>>& G, vector<vector<ll>>& dist) {
    int N = G.size();
    dist = vector(N, vector<ll>(N, INF));
    for (int from = 0; from < N; from++) {
        for (auto [to, cost] : G[from]) {
            dist[from][to] = cost;
        }
    }
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int to = 0; to < N; to++) {
            for (int from = 0; from < N; from++) {
                if (dist[from][i] == INF || dist[i][to] == INF) continue;
                dist[from][to] =
                    min(dist[from][to], dist[from][i] + dist[i][to]);
            }
        }
    }

    // 負の閉路検知
    for (int i = 0; i < N; i++) {
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
        int A, B, C;
        cin >> A >> B >> C, A--; B--;
        G[A].emplace_back(B, C);
        G[B].emplace_back(A, C);
    }

    vector dist(N, vector<ll>(N));
    warsahll_floyd(G, dist);
    debug(dist);

    int ans = 0;
    for(int from = 0; from < N; from++){
        for(auto [to, cost]: G[from]){
            if(from > to) continue;

            ll m = INF;
            // この辺がない場合の from, to の最短距離を求める
            for(int i = 0; i < N; i++){
                if(i == from || i == to) continue;
                m = min(m, dist[from][i] + dist[i][to]);
            }
            // m <= cost ならこの辺は不要
            if(m <= cost) ans++;
        }
    }

    cout << ans << endl;
}