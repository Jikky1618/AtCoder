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

struct UnionFind {
    int n, counter;
    vector<int> data;
    UnionFind(int size) : n(size), counter(size), data(size, -1) {}
    int root(int x) { return (data[x] < 0 ? x : data[x] = root(data[x])); }
    bool same(int x, int y) { return root(x) == root(y); }
    bool merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (-data[x] < -data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        counter--;
        return true;
    }
    int size(int x) { return -data[root(x)]; }
    int size() { return counter; }
    vector<int> group(int x) {
        vector<int> res;
        for(int i = 0; i < n; i++) if(same(x, i)) res.emplace_back(i);
        return res;
    }
    vector<vector<int>> groups() {
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++) res[root(i)].emplace_back(i);
        res.erase(remove_if(res.begin(), res.end(), [&](const vector<int>& v) {
            return v.empty();
        }), res.end());
        return res;
    }
};

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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    UnionFind uf(N);
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int U, V; cin >> U >> V, U--, V--;
        if(A[U] > A[V]) swap(U, V);
        if(A[U] == A[V]){
            uf.merge(U, V);
        }else{
            G[U].emplace_back(V);
        }
    }
    
    // 縮約したグラフを構築
    vector<vector<int>> G2(N);
    for(int from = 0; from < N; from++){
        for(auto to: G[from]){
            // 同じ連結成分に属している場合は continue
            if(uf.same(from, to)) continue;
            G2[uf.root(from)].emplace_back(uf.root(to));
        }
    }

    auto order = topological_sort(G2);
    vector<int> dp(N, -INF);
    dp[uf.root(0)] = 1;
    for(auto from: order){
        if(dp[from] == -INF) continue;
        for(auto to: G2[from]){
            dp[to] = max(dp[to], dp[from] + 1);
        }
    }

    cout << (dp[uf.root(N - 1)] == -INF ? 0 : dp[uf.root(N - 1)]) << '\n';
}