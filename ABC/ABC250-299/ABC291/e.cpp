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
    vector<set<int>> G(N);
    for(int i = 0; i < M; i++){
        int X, Y; cin >> X >> Y, X--, Y--;
        G[X].insert(Y);
    }

    // トポロジカルソート
    vector<int> seen(N), order;
    auto dfs = [&](auto &&self, int pos) -> void {
        seen[pos] = 1;

        for(auto np: G[pos]){
            if(seen[np]) continue;
            self(self, np);
        }
        order.push_back(pos);
    };

    for(int i = 0; i < N; i++){
        if(seen[i]) continue;
        dfs(dfs, i);
    }
    reverse(order.begin(), order.end());

    bool flag = false;
    for(int i = 0; i < N - 1; i++){
        // トポソした隣同士の要素に辺があるか判定
        if(G[order[i]].count(order[i + 1]) == 0) flag = true;
    }

    if(flag){
        cout << "No" << endl;
        return 0;
    }else{
        cout << "Yes" << endl;
    }

    vector<int> ans(N);
    for(int i = 0; i < N; i++) ans[order[i]] = i + 1;

    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N - 1];
    }
}