#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    // 無向グラフの入力
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<bool> seen(N);
    auto dfs = [&](int pos, auto self) -> void {
        seen[pos] = true;
        for(auto np: G[pos]){
            if(seen[np] == 1) continue;
            self(np, self);
        }
    };
    dfs(0, dfs);

    bool flag = true;
    for(auto f: seen) if(f == false) flag = false;

    cout << (flag ? "The graph is connected." : "The graph is not connected.") << endl;
}