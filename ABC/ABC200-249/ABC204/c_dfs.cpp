#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> visited;
void dfs(int pos, vector<vector<int>> &graph){
    visited[pos] = true;
    for(auto next_pos: graph[pos]){
        if(visited[next_pos] == false) dfs(next_pos, graph);
    }
}

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

    visited.resize(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int i = 0; i < n; i++) visited[i] = false;
        dfs(i, graph);
        for(int i = 0; i < n; i++) ans += (visited[i] == true);
    }

    cout << ans << endl;
    return 0;
}