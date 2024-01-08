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

vector<vector<int>> strong_connected_components(const vector<vector<int>>& G) {
    int n = G.size();
    // 辺が逆向きのグラフを構築
    vector<vector<int>> rG(n);
    for (int i = 0; i < n; i++) {
        for (auto e : G[i]) {
            rG[e].emplace_back(i);
        }
    }

    // status[i] := 頂点iの状態(0: dfs未探索, 1: dfs探索済み, 2: dfs,
    // rdfs探索済み)
    vector<int> status(n);
    // 帰りがけ順をスタックに載せる
    stack<int> stk;

    auto dfs = [&](auto&& self, int pos) -> void {
        status[pos] = 1;
        for (auto np : G[pos]) {
            if (status[np] == 1) continue;
            status[pos] = 1;
            self(self, np);
        }
        stk.push(pos);
    };

    // 帰りがけ順をdfs
    for (int i = 0; i < n; i++) {
        if (status[i] == 0) dfs(dfs, i);
    }

    auto rdfs = [&](auto&& self, int pos, vector<int>& v) -> void {
        status[pos] = 2;
        for (auto np : rG[pos]) {
            if (status[np] == 2) continue;
            self(self, np, v);
        }
        v.emplace_back(pos);
    };

    vector<vector<int>> res;
    // 帰りがけ順が大きい順からrdfsして、行けた頂点が一つの強連結成分
    while (!stk.empty()) {
        int pos = stk.top();
        stk.pop();
        if (status[pos] == 2) continue;
        // v := posからrdfsして行けた頂点
        vector<int> v;
        rdfs(rdfs, pos, v);
        res.emplace_back(v);
    }
    return res;
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int U, V; cin >> U >> V, U--, V--;
        if(A[U] > A[V]) swap(U, V);
        if(A[U] == A[V]){
            G[U].emplace_back(V);
            G[V].emplace_back(U);
        }else{
            G[U].emplace_back(V);
        }
    }
    
    auto scc = strong_connected_components(G);
    int K = scc.size();

    // B[i] := 頂点 i が属する強連結成分の番号
    vector<int> B(N);
    for(int i = 0; i < K; i++) for(auto v: scc[i]) B[v] = i;
    
    // 辺を全探索して, 強連結成分同士の関係をグラフにする
    vector<vector<int>> dag(K);
    for(int from = 0; from < N; from++){
        for(auto&& to: G[from]){
            // 同じ連結成分に属している場合は continue
            if(B[from] == B[to]) continue;
            dag[B[from]].emplace_back(B[to]);
        }
    }

    // 頂点 0 が属する強連結成分から DP していく
    vector<int> dp(K, -INF);
    dp[B[0]] = 1;
    for(int from = 0; from < K; from++){
        if(dp[from] == -INF) continue;
        for(auto to: dag[from]){
            dp[to] = max(dp[to], dp[from] + 1);
        }
    }

    cout << (dp[B[N - 1]] == -INF ? 0 : dp[B[N - 1]]) << '\n';
}