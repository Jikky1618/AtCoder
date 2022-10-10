#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> visited;
vector<int> ans;
bool found;
void dfs(int pos, int goal, const vector<vector<int>> &graph){
    // goalに到達していない場合、パスをメモ
    if(!found) ans.push_back(pos);
    visited[pos] = true;
    if(pos == goal) found = true;
    for(auto next_pos: graph[pos]){
        if(visited[next_pos] == false) dfs(next_pos, goal, graph);
    }
    // goalに到達していない場合、メモを削除
    // 到達していれば、メモは削除されない
    if(!found) ans.pop_back();
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x,y;
    cin >> n >> x >> y; x--; y--;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited.resize(n);
    dfs(x,y,graph);

    for(auto i:ans) cout << i + 1 << endl;
    return 0;
}