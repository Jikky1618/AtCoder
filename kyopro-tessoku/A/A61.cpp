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
        graph[b].push_back(a);
    }
    
    // 出力
    for(int i = 0; i < n; i++){
        cout << i + 1 << ": {";
        for(int j = 0; j < graph[i].size(); j++){
            if(j == 0) cout << graph[i][j] + 1;
            else cout << ", " << graph[i][j] + 1;
        }
        cout << "}" << endl;
    }
    return 0;
}