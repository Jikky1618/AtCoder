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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int U, V; cin >> U >> V, U--, V--;
        if(A[U] > A[V]) swap(U, V);
        if(A[U] == A[V]){
            G[U].emplace_back(V, 0);
            G[V].emplace_back(U, 0);
        }else{
            G[U].emplace_back(V, 1);
        }
    }

    // dijkstra
    vector<int> dist(N, -INF);
    dist[0] = 1;
    // {A[i], -dist[i], i} を持って, A[i] の昇順に処理
    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> que;
    que.emplace(A[0], -1, 0);
    
    while(!que.empty()){
        auto [a, expected, from] = que.top(); que.pop();
        if(dist[from] > -expected) continue;
        for(auto [to, cost]: G[from]){
            if(dist[to] < dist[from] + cost){
                dist[to] = dist[from] + cost;
                que.emplace(A[to], -dist[to], to);
            }
        }
    }

    cout << (dist[N - 1] < 0 ? 0 : dist[N - 1]) << '\n';
}