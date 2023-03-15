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
        int A, B; cin >> A >> B, A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    for(int i = 0; i < N; i++){
        vector<int> dist(N, -1);
        queue<int> que;
        dist[i] = 0;
        que.push(i);
        while(!que.empty()){
            int pos = que.front(); que.pop();
            for(auto np: G[pos]){
                if(dist[np] != -1) continue;
                dist[np] = dist[pos] + 1;
                que.push(np);
            }
        }

        int ans = 0;
        for(int j = 0; j < N; j++){
            if(2 == dist[j]) ans++;
        }

        cout << ans << endl;
    }
}