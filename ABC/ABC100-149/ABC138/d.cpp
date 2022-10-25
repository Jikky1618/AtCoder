#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int pos, int p, vector<vector<int>> &graph, vector<int> &res){
    if(p != -1) res[pos] += res[p];
    for(auto &&npos: graph[pos]){
        if(npos == p) continue;
        dfs(npos, pos, graph, res);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // imos法
    vector<int> sum(n);
    for(int i = 0; i < q; i++){
        int p,x; cin >> p >> x; p--;
        sum[p] += x;
    }

    dfs(0, -1, graph, sum);
    for(auto &&i: sum) cout << i << " ";
    cout << endl;
    return 0;
}