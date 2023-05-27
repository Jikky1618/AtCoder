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
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(v), G[v].emplace_back(u);
    }

    // 星の中心であるような頂点を１つ探す
    int start = -1;
    for(int i = 0; i < N; i++){
        // まず葉を探す
        if(G[i].size() == 1){
            // 葉の隣接頂点が星の中心
            start = G[i].front();
            break;
        }
    }

    // その頂点からBFS
    vector<int> dist(N, -1);
    queue<int> que;
    dist[start] = 0;
    que.emplace(start);

    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(dist[np] != -1) continue;
            dist[np] = dist[pos] + 1;
            que.emplace(np);
        }
    }

    // dist の 3 の倍数の頂点が星の中心
    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(dist[i] % 3 == 0){
            ans.emplace_back(G[i].size());
        }
    }

    sort(ans.begin(), ans.end());
    int M = ans.size();
    for(int i = 0; i < M; i++){
        cout << ans[i] << " \n"[i == M - 1];
    }
}