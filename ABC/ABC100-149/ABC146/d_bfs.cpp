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

    vector<int> ans(N - 1); // 辺の色を表す配列
    vector<int> seen(N); // 既に到達したかどうかを表す配列
    queue<pair<int, int>> que; // {頂点, 前回の色}

    seen[0] = 1;
    que.push({0, -1});

    while(!que.empty()){
        auto [pos, col] = que.front(); que.pop();
        int color = 1;
        if(color == col) color++; // 前回の色と同じならずらす
        for(auto [np, nc]: G[pos]){ // posと隣接している{頂点, 辺番号}
            if(seen[np]) continue; // 既に到達済みならcontinue
            seen[np] = 1;
            ans[nc] = color; // 到達した辺をcolorにする
            que.push({np, color}); // {新しく到達した頂点, 辺の色}
            color++;
            if(color == col) color++; // 親から来た辺の色と被ったならずらす
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;
    for(int i = 0; i < N - 1; i++) cout << ans[i] << endl;
}