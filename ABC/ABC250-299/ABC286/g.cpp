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
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> E;
    for(int i = 0; i < M; i++){
        int U, V; cin >> U >> V, U--, V--;
        E.emplace_back(U, V);
    }
    int K;
    cin >> K;
    vector<bool> once(M);
    for(int i = 0; i < K; i++){
        int X; cin >> X, X--;
        once[X] = true;
    }

    UnionFind uf(N);
    // S に含まれない辺の縮約
    for(int i = 0; i < M; i++){
        if(once[i]) continue;
        auto [U, V] = E[i]; 
        uf.merge(U, V);
    }

    // 辺の縮約をしたグラフの次数を求める
    vector<int> deg(N);
    for(int i = 0; i < M; i++){
        if(once[i]){
            auto [U, V] = E[i];
            deg[uf.root(U)]++;
            deg[uf.root(V)]++;
        }
    }

    // 奇数の次数が 2 以下ならオイラー路が存在する
    int odd = 0;
    for(int i = 0; i < N; i++) odd += (deg[i] % 2 == 1);

    cout << (odd <= 2 ? "Yes" : "No") << endl;
}