#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // 無向グラフの入力
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // dist := スタート位置からの各頂点の距離(初期化-1)
    vector<int> dist(n, -1);
    // que := 発見したが未到達の頂点を格納
    queue<int> que;

    // 初期条件(頂点0)
    dist[0] = 0;
    que.push(0);

    // 幅優先探索
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto next_pos: graph[pos]){
            if(dist[next_pos] != -1) continue;
            dist[next_pos] = dist[pos] + 1;
            que.push(next_pos);
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist[i] << endl;
    }
    return 0;
}