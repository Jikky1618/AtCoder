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
    ll N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    // 部分木のサイズを求める
    vector<ll> sub(N);
    auto dfs = [&](auto&& self, int pos, int prev) -> void {
        sub[pos] = 1;
        for(auto&& np : G[pos]){
            if(np == prev) continue;
            self(self, np, pos);
            sub[pos] += sub[np];
        }
    };
    dfs(dfs, 0, -1);

    // 余事象を求める
    ll cnt = 0;
    for(int i = 0; i < N; i++) cnt += sub[i] * (N - sub[i]);
    cnt -= N * (N - 1) / 2;

    // 答えは全事象から余事象を引いたもの
    ll ans = N * (N - 1) * (N - 2) / 6 - cnt;
    cout << ans << endl;
}