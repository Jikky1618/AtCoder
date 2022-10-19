#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    vector<int> p(n);
    for(int i = 0; i < n; i++) p[i] = i;
    int ans = 0;
    do{
        if(p[0] != 0) break; // 1番目が1でなければbreak;
        bool flag = true;
        for(int i = 0; i < n - 1; i++){
            bool found = false;
            for(auto pos: graph[p[i]]){
                // 隣接していればtrue
                if(pos == p[i + 1]) found = true;
            }
            if(!found) flag = false;
        }
        if(flag) ans++;
    }while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    return 0;
}