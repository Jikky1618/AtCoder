#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind{
    vector<int> parent, sizes; // parent[i] := iの親要素, sizes[i] := iの属する木の頂点数
    // 構造体の初期化
    UnionFind(int n): parent(n,-1), sizes(n,1) {}

    // root(x): 要素xの根を返す
    int root(int x){
        if(parent[x] == -1) return x; // xが根の場合xを返す
        return parent[x] = root(parent[x]); // 経路圧縮
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
    int N;
    cin >> N;

    vector<string> S(N), T(N);
    for(int i = 0; i < N; i++) cin >> S[i] >> T[i];

    map<string, int> id;
    for(int i = 0; i < N; i++) if(!id.count(S[i])) id[S[i]] = id.size();
    for(int i = 0; i < N; i++) if(!id.count(T[i])) id[T[i]] = id.size();

    UnionFind uf(id.size());
    bool flag = true;
    for(int i = 0; i < N; i++){
        if(uf.same(id[S[i]], id[T[i]])) flag = false;
        else uf.merge(id[S[i]], id[T[i]]);
    }

    cout << (flag ? "Yes" : "No") << endl;
}