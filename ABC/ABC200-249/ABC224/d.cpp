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
    // グラフの入力
    int N = 9, M;
    cin >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // 初期頂点の集合を入力
    vector<int> s(N, -1);
    for(int i = 0; i < N - 1; i++){
        int p; cin >> p; p--;
        s[p] = i;
    }

    // 目的の頂点の配列
    vector<int> t(N, -1);
    for(int i = 0; i < N - 1; i++) t[i] = i;

    // dist := 1-8の集合、到達回数
    map<vector<int>, int> dist;
    // que := 発見したが未到達の1-8の集合を格納
    queue<vector<int>> que;

    // 初期化
    dist[s] = 0;
    que.push(s);

    // 幅優先探索
    while(!que.empty()){
        auto pos = que.front(); que.pop();
        // 空の頂点を全探索
        for(int v = 0; v < N; v++){
            // 空の頂点でなければcontinue
            if(pos[v] != -1) continue;
            // vと交換できる頂点を全探索
            for(auto u: G[v]){
                auto np = pos;
                swap(np[u], np[v]); // 交換
                // 既にnpは到達済ならcontinue
                if(dist.find(np) != dist.end()) continue;
                dist[np] = dist[pos] + 1;
                que.push(np);
            }
        }
    }

    cout << (dist.find(t) == dist.end() ? -1 : dist[t]) << endl;
}