#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    for(int i = 1; i < N; i++){
        int B; cin >> B, B--;
        G[B].push_back(i);
    }
    debug(G);

    auto dfs = [&](auto &&self, int pos, int p) -> int {
        int p_max = -INF, p_min = INF;
        for(auto np: G[pos]){
            if(np == p) continue; // 親には戻らない

            int val = self(self, np, pos);
            p_max = max(p_max, val);
            p_min = min(p_min, val);
        }
        return p_max + p_min + 1;
    };

    cout << dfs(dfs, 0, -1) << endl;
}