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
        G[u].push_back(v);
    }

    ll ans = 0; // 各点から到達可能な辺の数を求める
    for(int i = 0; i < N; i++){
        vector<int> seen(N);
        queue<int> que;

        seen[i] = 1;
        que.push(i);
        while(!que.empty()){
            int pos = que.front(); que.pop();
            for(auto np: G[pos]){
                if(seen[np] == 1) continue;
                seen[np] = 1;
                que.push(np);
                ans++;
            }
        }
    }

    ans -= M; // 既にある辺の個数を引く
    cout << ans << endl;
}