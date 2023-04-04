#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<int> topological_sort(const vector<vector<int>> &G){
    int n = G.size();
    // 入次数を求める
    vector<int> indegree(n);
    for(int i = 0; i < n; i++){
        for(auto e: G[i]) indegree[e]++;
    }

    // 入次数0の頂点から取り除く
    // 辞書順最小を求めるためにpriority_queを使用
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i = 0; i < n; i++) if(indegree[i] == 0) que.push(i);

    vector<int> order;
    while(!que.empty()){
        int pos = que.top(); que.pop();
        order.emplace_back(pos);
        for(auto e: G[pos]){
            indegree[e]--;
            if(indegree[e] == 0) que.push(e);
        }
    }

    return ((int)order.size() == n ? order : vector<int>{});
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].push_back(B);
    }

    // トポロジカルソート
    vector<int> ans = topological_sort(G);

    if(ans.empty()){
        cout << -1 << "\n";
    }else{
        for(int i = 0; i < N; i++){
            cout << ans[i] + 1 << " \n"[i == N - 1];
        }
    }
}