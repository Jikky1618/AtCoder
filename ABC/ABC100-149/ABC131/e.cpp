#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int N, K;
    cin >> N >> K;

    // star: K = (N - 1)C2 が上限
    if(K < N - 2 || K > (N - 1) * (N - 2) / 2) {
        cout << -1 << '\n';
    } else {
        vector<pair<int, int>> edges;
        // star graph を生成
        for(int i = 1; i < N; i++) {
            edges.emplace_back(0, i);
        }
        int remain = (N - 1) * (N - 2) / 2 - K;
        for(int i = 1; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(remain == 0) break;
                edges.emplace_back(i, j);
                remain--;
            }
        }
        debug(edges);
        int M = edges.size();
        cout << M << '\n';
        for(auto [u, v] : edges) cout << u + 1 << " " << v + 1 << '\n';
    }
}