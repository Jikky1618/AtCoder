#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int from; // 辺の始点
    int to; // 辺の終点
    int cost; // 辺の重み
};

// Edgeの比較関数
bool comp(const Edge &x, const Edge &y){
    return x.cost > y.cost;
}

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
    // 辺のリストを入力
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for(int i = 0; i < M; i++){
        int A, B, C; cin >> A >> B >> C, A--, B--;
        edges[i] = {A, B, C};
    }


    // 辺のcostでソート
    sort(edges.begin(), edges.end(), comp);
    // UnionFindで全域木を表現
    UnionFind uf(N);
    // 最大全域木を求める
    int ans = 0;
    for(int i = 0; i < M; i++){
        auto [A, B, C] = edges[i];
        // もし、(A, B)が既に連結ならcontinue
        if(uf.same(A, B)) continue;
        // (A, B)の辺を接続
        uf.merge(A, B);
        // (A, B)のcostを増やす
        ans += C;
    }

    cout << ans << endl;
}