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
    int N, D;
    cin >> N >> D;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    // グラフを構築
    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            double dist = hypot(X[i] - X[j], Y[i] - Y[j]);
            if(dist <= D) G[i].emplace_back(j), G[j].emplace_back(i);
        }
    }

    // BFS
    vector<int> ans(N);
    queue<int> que;
    ans[0] = true;
    que.emplace(0);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(ans[np]) continue;
            ans[np] = true;
            que.emplace(np);
        }
    }

    for(int i = 0; i < N; i++){
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}