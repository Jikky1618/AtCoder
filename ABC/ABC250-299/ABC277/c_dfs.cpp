#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans = 0;
map<int, bool> visited;
void dfs(int pos, map<int,vector<int>> &graph){
    visited[pos] = true;
    ans = max(ans, pos);
    for(auto &&next_pos: graph[pos]){
        if(visited[next_pos] == false) dfs(next_pos, graph);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    map<int,vector<int>> graph;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, graph);

    cout << ans << endl;
    return 0;
}