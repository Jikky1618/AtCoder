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
    int N;
    cin >> N;
    // G[i] := 頂点iの{隣接頂点, 辺番号}
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b, a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    vector<int> res(N - 1);
    vector<int> dist(N, -1);
    queue<pair<int, int>> que;
    dist[0] = 0;
    que.push({0, -1});

    while(!que.empty()){
        auto [pos, col] = que.front(); que.pop();
        int color = 1;
        if(color == col) color++;
        for(auto [np, nc]: G[pos]){
            if(dist[np] != -1) continue;
            dist[np] = dist[pos] + 1;
            res[nc] = color;
            que.push({np, color});
            color++;
            if(color == col) color++;
        }
    }

    cout << *max_element(res.begin(), res.end()) << endl;
    for(int i = 0; i < N - 1; i++) cout << res[i] << endl;
}