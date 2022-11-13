#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Union-Find
struct UnionFind{
    // par[i] := iの親要素, rank[i] := iの属する木の高さ, sizes[i] := iの属する木の頂点数
    vector<int> par, rank, sizes;
    // 構造体の初期化
    UnionFind(int n): par(n,-1), rank(n,0), sizes(n,1) {}

    // 要素xの根を返す
    int root(int x){
        if(par[x] == -1) return x; // xが根の場合xを返す
        return par[x] = root(par[x]); // 経路圧縮
    }

    // xとyが同じグループに属するか (= 根が一致するか)
    bool same(int x, int y){
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループを併合
    bool unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        // union by rank
        if(rank[rx] < rank[ry]) swap(rx, ry);
        par[ry] = rx; 
        if(rank[rx] == rank[ry]) rank[rx]++;
        sizes[rx] += sizes[ry]; 
        return true;
    }
    
    int size(int x){
        return sizes[root(x)];
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int n, q;
    cin >> n >> q;
    
    UnionFind uf(n);
    for(int i = 0; i < q; i++){
        int Query, u, v;
        cin >> Query >> u >> v;
        if(Query == 1) uf.unite(u,v);
        if(Query == 2){
            if(uf.same(u,v)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}