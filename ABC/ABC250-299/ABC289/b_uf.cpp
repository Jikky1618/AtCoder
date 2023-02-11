#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    // parent[i] := iの親要素, sizes[i] := iの属する木の頂点数
    vector<int> parent, sizes;
    // 構造体の初期化
    UnionFind(int n): parent(n, -1), sizes(n, 1) {}

    // root(x): 要素xの根を返す(xが根の場合xを返す)
    int root(int x){
        return (parent[x] == -1 ? x : parent[x] = root(parent[x]));
    }

    // same(x, y): xとyが同じグループに属するかを返す (= 根が一致するか)
    bool same(int x, int y){
        return root(x) == root(y);
    }

    // merge(x, y): 要素x,yを併合する
    bool merge(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        if(sizes[rx] > sizes[ry]) swap(rx, ry); 
        sizes[rx] += sizes[ry]; 
        parent[ry] = rx;
        return true;
    }
    
	// size(x): 要素xの大きさを返す
    int size(int x){
        return sizes[root(x)];
    }

    // groups(): 連結成分を2次元配列で返す
    vector<vector<int>> groups(){
        vector<vector<int>> res(sizes.size());
        for(int i = 0; i < (int)sizes.size(); i++){
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
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i], A[i]--;
    
    UnionFind uf(N);
    for(int i = 0; i < M; i++){
        uf.merge(A[i], A[i] + 1);
    }

    auto G = uf.groups();
    debug(G);
    for(int i = 0; i < G.size(); i++){
        sort(G[i].begin(), G[i].end(), greater<int>());
        for(auto g: G[i]){
            cout << g + 1 << " ";
        }
    }
    cout << endl;
}