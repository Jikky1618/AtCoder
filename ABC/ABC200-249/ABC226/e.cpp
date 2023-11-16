#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

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
        int U, V; cin >> U >> V, U--, V--;
        G[U].emplace_back(V);
        G[V].emplace_back(U);
    }

    // 連結成分がなもりグラフなら x2, それ以外なら x0
    ll ans = 1;
    vector<int> seen(N);
    for(int i = 0; i < N; i++){
        if(seen[i]) continue;
        seen[i] = true;
        // 連結成分ごとに x 頂点, x 辺(= なもりグラフ)かどうかを判定する
        queue<int> que;
        que.emplace(i);
        int v = 0, e = 0;
        while(!que.empty()){
            int pos = que.front();
            que.pop();
            v++;
            for(auto np: G[pos]){
                e++;
                if(seen[np]) continue;
                seen[np] = true;
                que.emplace(np);
            }
        }
        ans *= (2 * v == e ? 2 : 0);
        if(ans > MOD) ans -= MOD;
    }

    cout << ans << '\n';
}