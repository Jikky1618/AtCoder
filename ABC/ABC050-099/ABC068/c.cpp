#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b, a--, b--;
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

    cout << (dist[N - 1] == 2 ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}