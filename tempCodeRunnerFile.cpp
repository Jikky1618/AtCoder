#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind{
    vector<int> par, sizes;
    UnionFind(int n): par(n,-1), sizes(n,1) {}

    int root(int x){
        if(par[x] == -1) return x; // xが根の場合xを返す
        return par[x] = root(par[x]); // 経路圧縮
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        // union by size
        if(sizes[rx] > sizes[ry]) swap(rx, ry); 
        sizes[rx] += sizes[ry]; 
        par[ry] = rx;
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
    int N, M, K;
    cin >> N >> M >> K;

    vector<set<int>> st(N);
    UnionFind uf(N);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b; a--, b--;
        st[a].insert(b), st[b].insert(a);
        uf.merge(a,b);
    }
    for(int i = 0; i < K; i++){
        int c, d; cin >> c >> d; c--, d--;
        st[c].insert(d), st[d].insert(c);
    }

    for(int i = 0; i < N; i++){
        cout << uf.size(i) - st[i].size() - 1 << endl;
    }
    return 0;
}