#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<int> topological_sort(const vector<vector<int>>& G) {
    int N = G.size();
    // 入次数を求める
    vector<int> indegree(N);
    for (int i = 0; i < N; i++) {
        for (auto e : G[i]) indegree[e]++;
    }

    // 入次数 0 の頂点から取り除く
    queue<int> que;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) que.emplace(i);
    }

    vector<int> order;
    while (!que.empty()) {
        // que の先頭の頂点を取り出す
        int pos = que.front();
        que.pop();

        // 頂点 pos を order に追加
        order.emplace_back(pos);
        // pos と隣接している頂点の入次数を 1 下げる
        for (auto e : G[pos]) {
            indegree[e]--;
            // 0 になれば, que に追加
            if (indegree[e] == 0) que.emplace(e);
        }
    }

    return ((int)order.size() == N ? order : vector<int>{});
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y, x--, y--;
        G[x].emplace_back(y);
    }

    // G をトポロジカルソートする
    auto p = topological_sort(G);
    // dp[i] := 頂点 i に到達したときの最長距離
    vector<int> dp(N);
    // トポロジカル順序の頂点順に dp を更新する
    for(int i = 0; i < N; i++){
        // 頂点 p[i] の隣接頂点に遷移
        for(auto np: G[p[i]]){
            dp[np] = max(dp[np], dp[p[i]] + 1);
        }
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;
}