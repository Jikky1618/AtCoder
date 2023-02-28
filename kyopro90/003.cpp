#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int tree_diameter(const vector<vector<int>>& G){
    int N = G.size();

    // 頂点0からBFS
    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(dist[np] != -1) continue;
            dist[np] = dist[pos] + 1;
            que.push(np);
        }
    }
    // 頂点0から最も遠い頂点xを求める
    int x = max_element(dist.begin(), dist.end()) - dist.begin();

    // 頂点xからBFS
    dist.assign(N, -1);
    dist[x] = 0;
    que.push(x);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(dist[np] != -1) continue;
            dist[np] = dist[pos] + 1;
            que.push(np);
        }
    }
    // 頂点xから最も遠い頂点までの距離が直径になる
    int d = *max_element(dist.begin(), dist.end());
    return d;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    cout << tree_diameter(G) + 1 << endl;
}