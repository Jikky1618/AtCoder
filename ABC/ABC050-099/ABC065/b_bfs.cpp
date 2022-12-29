#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        int a; cin >> a; a--;
        G[i].push_back(a);
    }

    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0, que.push(0);
    while(!que.empty()){
        int p = que.front(); que.pop();
        for(auto np: G[p]){
            if(dist[np] != -1) continue;
            dist[np] = dist[p] + 1;
            que.push(np);
        }
    }

    cout << dist[1] << endl;
    return 0;
}