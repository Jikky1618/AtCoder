#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--,b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n; i++) sort(graph[i].begin(), graph[i].end());

    for(auto &&i: graph){
        cout << i.size() << endl;
        for(auto &&j: i){
            cout << j + 1 << " ";
        }
        cout << endl;
    }


    return 0;
}