#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(dist[np] != -1) continue;
            dist[np] = dist[pos] + 1;
            que.push(np);
        }
    }

    while(Q--){
        int c, d; cin >> c >> d; c--, d--;
        if(dist[c] % 2 == dist[d] % 2){
            cout << "Town" << endl;
        }else{
            cout << "Road" << endl;
        }
    }
    return 0;
}