#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // グラフの入力
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a,b; 
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<bool> visited(n, false);
        queue<int> que;
        // 初期化
        visited[i] = true;
        que.push(i);
        // 幅優先探索
        while(!que.empty()){
            int pos = que.front(); que.pop();
            visited[pos] = true;
            for(auto next_pos: graph[pos]){
                if(visited[next_pos] == false) que.push(next_pos);
            }
        }
        // ans計算
        for(int j = 0; j < n; j++) ans += (visited[j] == true);
    }

    cout << ans << endl;
    return 0;
}