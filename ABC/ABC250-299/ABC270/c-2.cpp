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
    int N, X, Y;
    cin >> N >> X >> Y, X--, Y--;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int U, V; cin >> U >> V, U--, V--;
        G[U].emplace_back(V);
        G[V].emplace_back(U);
    }

    vector<int> prev(N, -1);
    queue<int> que;

    que.emplace(Y);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(np == prev[pos]) continue;
            prev[np] = pos;
            que.emplace(np);
        }
    }

    vector<int> ans;
    int pos = X;
    while(true){
        ans.emplace_back(pos + 1);
        if(pos == Y) break;
        pos = prev[pos];
    }

    int M = ans.size();
    for(int i = 0; i < M; i++){
        cout << ans[i] << " \n"[i == M - 1];
    }
}