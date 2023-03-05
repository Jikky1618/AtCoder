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
     // n := 要素数, group_size := 連結成分の個数
    int n, group_size;
    // parent_or_size[i] := iの親要素
    // parent_or_size[i] * -1 :=  iの属する連結成分の頂点数
    vector<int> parent_or_size;

    // 構造体の初期化
    UnionFind(int size): n(size), group_size(size), parent_or_size(size, -1) {}

    // root(x): 要素xの根を返す(xが根の場合xを返す)
    int root(int x){
        return (parent_or_size[x] < 0 ? x : parent_or_size[x] = root(parent_or_size[x]));
    }

    // same(x, y): xとyが同じ連結成分に属するかを返す (= 根が一致するか)
    bool same(int x, int y){
        return root(x) == root(y);
    }

    // merge(x, y): 要素x, yを併合する
    bool merge(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        if(-parent_or_size[rx] < -parent_or_size[ry]) swap(rx, ry); 
        parent_or_size[rx] += parent_or_size[ry]; 
        parent_or_size[ry] = rx;
        group_size--;
        return true;
    }

	// size(x): 要素xの連結成分の大きさを返す
    int size(int x){
        return -parent_or_size[root(x)];
    }

    // size(): 連結成分の個数を返す
    int size(){
        return group_size;
    }

    // group(x) : 要素xの連結成分を1次元配列で返す
    vector<int> group(int x){
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(same(x, i)) res.push_back(i);
        }
        return res;
    }

    // groups(): 連結成分を2次元配列で返す
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
    vector<int> u(M), v(M);
    for(int i = 0; i < M; i++){
        cin >> u[i] >> v[i], u[i]--, v[i]--;
    }

    UnionFind uf(N);
    for(int i = 0; i < M; i++) uf.merge(u[i], v[i]);

    vector<int> edge(N), vertex(N);
    for(int i = 0; i < N; i++) edge[uf.root(i)]++;
    for(int i = 0; i < M; i++) vertex[uf.root(u[i])]++;

    cout << (edge == vertex ? "Yes" : "No") << endl;
    
}