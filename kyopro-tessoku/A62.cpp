#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

vector<bool> visited;
void dfs(int pos, const vector<vector<int>> &graph){
    visited[pos] = true;
    for(int i = 0; i < graph[i].size(); i++){
        int nex = graph[pos][i];
        if(visited[nex] == false) dfs(nex, graph);
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
        debug(visited[i]);
        if(visited[i] == false) flag = false;
    }

    if(flag) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;
    return 0;
}