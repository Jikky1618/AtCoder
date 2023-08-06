#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int S, T, M;
    cin >> S >> T >> M;
    vector<vector<int>> G(S);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(v);
    }

    // V[x][y] := 頂点対 (x, y) と隣接している頂点集合 V1 内の頂点
    vector V(T, vector<int>(T, -1));

    for(int i = 0; i < S; i++){
        // 頂点 i に隣接している 2 つの頂点を全探索
        // 全探索する頂点は全て頂点集合 V2 内
        for(auto x: G[i]){
            for(auto y: G[i]){
                if(x == y) continue;
                // -1 なら頂点対 (x, y) は i と隣接ことをメモ
                if(V[x - S][y - S] == -1){
                    V[x - S][y - S] = i;
                // -1 でないなら既に V[x - S][y - S] と (x, y) は隣接している
                // x, y, V[x - S][y - S], i はサイクルになっている
                }else{
                    int p1 = i + 1, p2 = V[x - S][y - S] + 1, p3 = x + 1, p4 = y + 1;
                    cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;
}