#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    // 結ばれているかを記録する2次元配列
    vector<vector<bool>> adj(n,vector<bool>(n));
    // 頂点u,vは結ばれている
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u][v] = adj[v][u] = true;
    }
    // aとb,bとc,cとaは結ばれているか全探索
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(adj[i][j] && adj[j][k] && adj[k][i]) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}