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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y, X--, Y--;
        G[X].emplace_back(Y);
    }

    vector<set<int>> G2(N);
    for(int i = 0; i < N; i++){
        for(auto e: G[i]){
            G2[i].insert(e);
        }
    }

    auto order = topological_sort(G);

    bool flag = true;
    // トポソ順にしたとき, 隣同士の要素に辺があれば一意に定まる
    for(int i = 0; i < N - 1; i++){
        if(!G2[order[i]].count(order[i + 1])) flag = false;
    }

    if(flag){
        cout << "Yes" << endl;
        vector<int> ans(N);
        for(int i = 0; i < N; i++) ans[order[i]] = i + 1;
        for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
    }else{
        cout << "No" << endl;
    }
}