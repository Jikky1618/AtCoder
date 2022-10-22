#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int v, int p, vector<int> &depth, const vector<vector<int>> &g){
    if(v == 1) depth[v] = 0;
    else depth[v] = depth[p] + 1;

    for(auto ch: g[v]){
        if(depth[ch] != 0) continue;
        dfs(ch, v, depth, g);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // 入力
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> graph(2 * n + 2);
    for(int i = 1; i <= n; i++){
        graph[a[i - 1]].push_back(i * 2);
        graph[i * 2].push_back(a[i - 1]);
        graph[a[i - 1]].push_back(i * 2 + 1);
        graph[i * 2 + 1].push_back(a[i - 1]);
    }

    vector<int> dep(2 * n + 2);
    dfs(1, 0, dep, graph);

    for(int i = 1; i <= 2 * n + 1; i++) cout << dep[i] << endl;

    return 0;
}