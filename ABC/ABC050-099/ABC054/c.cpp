#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> visited;
void dfs(int pos,int &res, const vector<vector<int>> &graph){
    bool flag = true;
    for(int i = 0; i < visited.size(); i++){
        if(!visited[i] && pos != i) flag = false; 
    }
    if(flag){ res++; return;}

    visited[pos] = true;
    for(auto npos: graph[pos]){
        if(visited[npos]) continue;
        dfs(npos, res, graph);
    }
    visited[pos] = false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    visited.resize(n);
    int ans = 0;
    dfs(0, ans, graph);

    cout << ans << endl;
    return 0;
}