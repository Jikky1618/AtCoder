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
        int u, v; cin >> u >> v, u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int K;
    cin >> K;
    vector<int> p(K), d(K);
    for(int i = 0; i < K; i++) cin >> p[i] >> d[i], p[i]--;

    // col[i] := 0なら白確定, 1なら白確定ではない(黒)
    vector<int> col(N, 1);
    for(int i = 0; i < K; i++){
        vector<int> dist(N, -1);
        queue<int> que;

        dist[p[i]] = 0;
        que.emplace(p[i]);

        while(!que.empty()){
            int pos = que.front(); que.pop();
            for(auto np: G[pos]){
                if(dist[np] != -1) continue;
                dist[np] = dist[pos] + 1;
                que.emplace(np);
            }
        }

        // 距離がd[i]未満は必ず白色
        bool flag = true;
        for(int j = 0; j < N; j++){
            if(dist[j] != -1 && dist[j] < d[i]) col[j] = 0;
        }
    }

    for(int i = 0; i < K; i++){
        vector<int> dist(N, -1);
        queue<int> que;

        dist[p[i]] = 0;
        que.emplace(p[i]);

        while(!que.empty()){
            int pos = que.front(); que.pop();
            for(auto np: G[pos]){
                if(dist[np] != -1) continue;
                dist[np] = dist[pos] + 1;
                que.emplace(np);
            }
        }

        bool flag = true;
        for(int j = 0; j < N; j++){
            // 距離d[i]に確定白でない頂点がなければfalse
            if(dist[j] == d[i] && col[j] == 1) flag = false;
        }

        if(flag){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for(int i = 0; i < N; i++){
        cout << col[i];
    }
    cout << endl;
}