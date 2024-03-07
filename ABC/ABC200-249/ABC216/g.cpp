#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& G, int start = 0) {
    int N = G.size();
    vector<T> dist(N, numeric_limits<T>::max());
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    dist[start] = 0;
    que.emplace(dist[start], start);
    while (!que.empty()) {
        auto [expected, from] = que.top();
        que.pop();
        // 最短距離でない場合, continue
        if (dist[from] < expected) continue;
        for (auto&& [to, cost] : G[from]) {
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                que.emplace(dist[to], to);
            }
        }
    }
    return dist;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<ll> L(M), R(M), X(M);
    for(int i = 0; i < M; i++) cin >> L[i] >> R[i] >> X[i], L[i]--;

    vector<vector<pair<int, int>>> G(N + 1);
    for(int i = 0; i < N; i++){
        G[i].emplace_back(i + 1, 1);
        G[i + 1].emplace_back(i, 0);
    }
    for(int i = 0; i < M; i++){
        G[L[i]].emplace_back(R[i], R[i] - L[i] - X[i]);
    }

    auto dist = dijkstra(G);
    debug(G, dist);

    vector<int> ans(N);
    for(int i = 0; i < N; i++) ans[i] = (dist[i] == dist[i + 1]);

    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N - 1];
    }
}