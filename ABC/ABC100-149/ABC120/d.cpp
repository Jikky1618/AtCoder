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
    ll n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
    }

    UnionFind uf(n);
    vector<ll> ans(m + 1);
    ans[0] = n * (n - 1) / 2;
    for(int i = 0; i < m; i++){
        if(uf.same(a[m - i - 1],b[m - i - 1])){
            ans[i + 1] = ans[i];
        }else{
            ans[i + 1] = ans[i] - 1LL * uf.size(a[m - i - 1]) * uf.size(b[m - i - 1]);
            uf.unite(a[m - i - 1],b[m - i - 1]);
        }
    }
    reverse(ans.begin(), ans.end());

    for(int i = 1; i <= m; i++) cout << ans[i] << endl;
    return 0;
}