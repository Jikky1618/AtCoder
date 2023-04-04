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
    int N;
    cin >> N;
    vector<pair<int, int>> X(N), Y(N);
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        X[i] = {x, i}, Y[i] = {y, i};
    }

    // グラフを構築する
    vector<tuple<int, int, int>> G;

    // Xでソート -> 隣同士の要素の辺を追加
    sort(X.begin(), X.end());
    for(int i = 0; i < N - 1; i++){
        int cost = abs(X[i].first - X[i + 1].first);
        G.emplace_back(cost, X[i].second, X[i + 1].second);
    }
    // Yでソート -> 隣同士の要素の辺を追加
    sort(Y.begin(), Y.end());
    for(int i = 0; i < N - 1; i++){
        int cost = abs(Y[i].first - Y[i + 1].first);
        G.emplace_back(cost, Y[i].second, Y[i + 1].second);
    }

    // クラスカル法
    sort(G.begin(), G.end());
    ll ans = 0;
    UnionFind uf(N);
    for(auto [cost, from, to]: G){
        if(!uf.same(from, to)){
            uf.merge(from, to);
            ans += cost;
        }
    }

    cout << ans << endl;
}