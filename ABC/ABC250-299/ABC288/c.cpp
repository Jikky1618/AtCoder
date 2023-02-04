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
    // parent[i] := iの親要素, sizes[i] := iの属する木の頂点数
    vector<int> parent, sizes;
    // 構造体の初期化
    UnionFind(int n): parent(n,-1), sizes(n,1) {}

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
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    int ans = 0;
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B, A--, B--;
        if(uf.same(A, B)) ans++;
        else uf.merge(A, B);
    }

    cout << ans << endl;
}