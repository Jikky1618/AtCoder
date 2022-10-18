#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> visited;
void dfs(int pos, const vector<vector<int>> &graph){
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
        graph[b].push_back(a);
    }
    visited.resize(n);
    dfs(0, graph);

    bool flag = true;
    for(int i = 0; i < n; i++){
        if(visited[i] == false) flag = false;
    }

    if(flag) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;
    return 0;
}