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
    int N, Q;
    cin >> N >> Q;
    vector<int> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    vector<vector<int>> T(N);
    auto dfs = [&](auto&& self, int pos, int p) -> void {
        T[pos].emplace_back(X[pos]);
        for(auto np: G[pos]){
            if(np == p) continue;
            self(self, np, pos);
            for(auto i: T[np]){
                T[pos].emplace_back(i);
            }
        }
        sort(T[pos].begin(), T[pos].end(), greater<int>());
        while(T[pos].size() > 20) T[pos].pop_back();
    };

    dfs(dfs, 0, -1);
    debug(T);

    while(Q--){
        int V, K; cin >> V >> K, V--, K--;
        cout << T[V][K] << '\n';
    }
}