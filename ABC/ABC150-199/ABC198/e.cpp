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
    vector<int> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    vector<int> ans(N);
    vector<int> col(1e5 + 1);
    auto dfs = [&](auto&& self, int pos, int p) -> void {
        ans[pos] = (col[C[pos]] ? false : true);
        col[C[pos]]++;
        for(auto&& np: G[pos]){
            if(np == p) continue;
            self(self, np, pos);
        }
        col[C[pos]]--;
    };

    dfs(dfs, 0, -1);
    for(int i = 0; i < N; i++){
        if(ans[i]) cout << i + 1 << "\n";
    }
} 