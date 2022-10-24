#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool good = true;
        for(auto &&pos: graph[i]){
            if(h[i] <= h[pos]) good = false;
        }
        if(good) ans++;
    }

    cout << ans << endl;
    return 0;
}