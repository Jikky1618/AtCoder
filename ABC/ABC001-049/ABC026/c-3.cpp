#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> B(N);
    for(int i = 1; i < N; i++) cin >> B[i];

    // グラフの作成
    vector<vector<int>> G(N);
    for(int i = 1; i < N; i++){
        G[i].emplace_back(B[i] - 1);
        G[B[i] - 1].emplace_back(i);
    }
    debug(G);

    vector<int> val(N, -1); // val[i] :~ 社員iの給料
    auto dfs = [&](auto&& self, int pos, int prev) -> void {
        int Max = -INF, Min = INF;
        for(auto np: G[pos]){
            if(np == prev) continue;
            self(self, np, pos);
            Max = max(Max, val[np]);
            Min = min(Min, val[np]);
        }
        
        val[pos] = Max + Min + 1;
    };

    dfs(dfs, 0, -1);

    cout << val[0] << endl;
}