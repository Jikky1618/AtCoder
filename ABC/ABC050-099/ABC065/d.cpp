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

// 重み付き無向グラフの最小全域木の長さを求める
ll kruskal(const vector<vector<pair<int, int>>> &G){
    int n = G.size();
    // {cost, from, to}のグラフを作成
    vector<tuple<ll, int, int>> edges;
    for(int from = 0; from < n; from++){
        for(auto [to, cost]: G[from]){
            edges.emplace_back(cost, from, to);
        }
    }
    sort(edges.begin(), edges.end());

    ll res = 0;
    UnionFind uf(n);
    for(auto [cost, from, to]: edges){
        if(!uf.same(from, to)){
            uf.merge(from, to);
            res += cost;
        }
    }

    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    vector<pair<int, int>> X2(N), Y2(N);
    for(int i = 0; i < N; i++){
        X2[i] = {X[i], i};
        Y2[i] = {Y[i], i};
    }

    // 最小全域木を求める問題
    // 普通に辺を貼ると O(N^2) 個
    // x の隣同士, y の隣同士の頂点で貼ると O(N) 個になる
    vector<vector<pair<int, int>>> G(N);
    
    // x をソート -> x の隣同士で辺を貼る
    sort(X2.begin(), X2.end());
    for(int i = 0; i < N - 1; i++){
        int id1 = X2[i].second, id2 = X2[i + 1].second;
        int dist = min(abs(X[id1] - X[id2]), abs(Y[id1] - Y[id2]));
        G[id1].emplace_back(id2, dist);
        G[id2].emplace_back(id1, dist);
    }

    // y をソート -> y の隣同士で辺を貼る
    sort(Y2.begin(), Y2.end());
    for(int i = 0; i < N - 1; i++){
        int id1 = Y2[i].second, id2 = Y2[i + 1].second;
        int dist = min(abs(X[id1] - X[id2]), abs(Y[id1] - Y[id2]));
        G[id1].emplace_back(id2, dist);
        G[id2].emplace_back(id1, dist);
    }

    ll ans = kruskal(G);
    cout << ans << endl;
}