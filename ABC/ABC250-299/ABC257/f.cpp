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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    // flag[i] := 都市 i に片方が未定となっているテレポーターが存在するか
    vector<int> flag(N);
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int U, V; cin >> U >> V, U--, V--;
        if (U < 0) {
            flag[V] = true;
        } else {
            G[U].emplace_back(V);
            G[V].emplace_back(U);
        }
    }

    auto bfs = [&](vector<ll>& dist, int st) -> void {
        dist[st] = 0;
        queue<int> que;
        que.emplace(st);
        while (!que.empty()) {
            int pos = que.front();
            que.pop();
            for (auto np : G[pos]) {
                if (dist[np] != INF) continue;
                dist[np] = dist[pos] + 1;
                que.emplace(np);
            }
        }
    };

    vector<ll> dist1(N, INF), dist2(N, INF);
    bfs(dist1, 0);
    bfs(dist2, N - 1);

    // pos1 := 1 から最も近い未定テレポーターの街
    // pos2 := N から最も近い未定テレポーターの街
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < N; i++) {
        if (!flag[i]) continue;
        if (pos1 == -1 || dist1[i] < dist1[pos1]) pos1 = i;
        if (pos2 == -1 || dist2[i] < dist2[pos2]) pos2 = i;
    }

    debug(flag, dist1, dist2, pos1, pos2);
    for (int i = 0; i < N; i++) {
        // 1 -> N
        ll ans = dist1[N - 1];
        // 1 -> pos1 -> i -> N
        if (pos1 != -1) ans = min(ans, dist1[pos1] + 1 + dist2[i]);
        // 1 -> i -> pos2 -> N
        if (pos2 != -1) ans = min(ans, dist1[i] + 1 + dist2[pos2]);
        // 1 -> pos1 -> i -> pos2 -> N
        if (pos1 != -1 && pos2 != -1) ans = min(ans, dist1[pos1] + 2 + dist2[pos2]);
        cout << (ans == INF ? -1 : ans) << " \n"[i == N - 1];
    }
}