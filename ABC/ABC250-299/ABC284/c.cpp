#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    vector<bool> seen(N, false);
    for(int i = 0; i < N; i++){
        if(seen[i] == true) continue;
        ans++;
        queue<int> que;
        que.push(i);
        seen[i] = true;
        while(!que.empty()){
            int pos = que.front(); que.pop();
            for(auto np: G[pos]){
                if(seen[np] == true) continue;
                seen[np] = true;
                que.push(np);
            }
        }
    }

    cout << ans << endl;
}