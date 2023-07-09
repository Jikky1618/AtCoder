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
    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    vector<vector<int>> G(N1 + N2);
    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    // 頂点 1 からの距離
    vector<int> dist1(N1 + N2, -1);
    queue<int> que;
    dist1[0] = 0;
    que.emplace(0);
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(auto np: G[pos]){
            if(dist1[np] != -1) continue;
            dist1[np] = dist1[pos] + 1;
            que.emplace(np);
        }
    }

    // 頂点 N1 + N2 からの距離
    vector<int> dist2(N1 + N2, -1);
    dist2[N1 + N2 - 1] = 0;
    que.emplace(N1 + N2 - 1);
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(auto np: G[pos]){
            if(dist2[np] != -1) continue;
            dist2[np] = dist2[pos] + 1;
            que.emplace(np);
        }
    }

    debug(dist1, dist2);
    ll ans = *max_element(dist1.begin(), dist1.end()) + *max_element(dist2.begin(), dist2.end()) + 1;
    cout << ans << endl;
}