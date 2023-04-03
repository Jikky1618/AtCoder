#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<vector<int>> strong_connected_components(const vector<vector<int>> &G){
    int n = G.size();
    // 辺が逆向きのグラフを構築
    vector<vector<int>> rG(n);
    for(int i = 0; i < n; i++){
        for(auto e: G[i]){
            rG[e].emplace_back(i);
        }
    }

    // status[i] := 頂点iの状態(0: dfs未探索, 1: dfs探索済み, 2: dfs, rdfs探索済み)
    vector<int> status(n);
    // 帰りがけ順をスタックに載せる
    stack<int> stk;

    auto dfs = [&](auto&& self, int pos) -> void {
        status[pos] = 1;
        for(auto np: G[pos]){
            if(status[np] == 1) continue;
            status[pos] = 1;
            self(self, np);
        }
        stk.push(pos);
    };
    
    // 帰りがけ順をdfs
    for(int i = 0; i < n; i++){
        if(status[i] == 0) dfs(dfs, i);
    }

    auto rdfs = [&](auto &&self, int pos, vector<int> &v) -> void {
        status[pos] = 2;
        for(auto np: rG[pos]){
            if(status[np] == 2) continue;
            self(self, np, v);
        }
        v.emplace_back(pos);
    };

    vector<vector<int>> res;
    // 帰りがけ順が大きい順からrdfsして、行けた頂点が一つの強連結成分
    while(!stk.empty()){
        int pos = stk.top(); stk.pop();
        if(status[pos] == 2) continue;
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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;

    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        G[i].emplace_back(A[i]);
    }

    auto scc = strong_connected_components(G);

    int ans = 0;
    for(auto e: scc){
        // サイクルの要素はすべて勝つことができる
        if(e.size() >= 2){
            ans += e.size();
        }else{
            // 自己サイクルの場合も勝つことができる 
            if(e.front() == A[e.front()]) ans++;
        }
    }

    cout << ans << endl;
}