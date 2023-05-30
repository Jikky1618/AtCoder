#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

struct UnionFind {
    int n, group_size;
    vector<int> parent_or_size;

    UnionFind(int size): n(size), group_size(size), parent_or_size(size, -1) {}

    int root(int x){
        return (parent_or_size[x] < 0 ? x : parent_or_size[x] = root(parent_or_size[x]));
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        if(-parent_or_size[rx] < -parent_or_size[ry]) swap(rx, ry); 
        parent_or_size[rx] += parent_or_size[ry]; 
        parent_or_size[ry] = rx;
        group_size--;
        return true;
    }

    int size(int x){
        return -parent_or_size[root(x)];
    }

    int group_count(){
        return group_size;
    }

    vector<int> group(int x){
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(same(x, i)) res.push_back(i);
        }
        return res;
    }

    vector<vector<int>> groups(){
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++){
            res[root(i)].push_back(i);
        }
        res.erase(remove_if(res.begin(), res.end(), [&](const vector<int>& v){
            return v.empty();
        }), res.end());
        return res;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, E;
    cin >> N >> M >> E;
    vector<pair<int, int>> Edges(E);
    for(int i = 0; i < E; i++){
        int U, V; cin >> U >> V, U--, V--;
        Edges[i] = {U, V};
    }

    int Q;
    cin >> Q;
    vector<int> q(Q);
    for(int i = 0; i < Q; i++) cin >> q[i], q[i]--;

    set<int> st;
    for(int i = 0; i < Q; i++) st.insert(q[i]);

    // 全ての発電所をつなげる超頂点を導入(地点N + M)
    UnionFind uf(N + M + 1);
    // 全ての発電所をつなげる超頂点と発電所をmerge
    for(int i = N; i < N + M; i++){
        uf.merge(i, N + M);
    }
    // 最終クエリ後で繋がってる電線をmerge
    for(int i = 0; i < E; i++){
        if(st.count(i)) continue;
        auto [U, V] = Edges[i];
        uf.merge(U, V);
    }

    vector<int> ans(Q);
    // クエリを逆順に処理
    for(int i = Q - 1; i >= 0; i--){
        // 超頂点のsize - 発電所の数 - 1 が答え
        int val = uf.size(N + M) - M - 1;
        ans[i] = val;
        auto [U, V] = Edges[q[i]];
        uf.merge(U, V);
    }

    for(int i = 0; i < Q; i++){
        cout << ans[i] << '\n';
    }
}