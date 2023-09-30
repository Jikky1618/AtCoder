#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    // to, x, y
    vector<vector<tuple<int, ll, ll>>> G(N);
    for(int i = 0; i < M; i++){
        ll A, B, X, Y; cin >> A >> B >> X >> Y, A--, B--;
        G[A].emplace_back(B, X, Y);
        G[B].emplace_back(A, -X, -Y);
    }
    debug(G);

    vector<pair<ll, ll>> dist(N, {INF, INF});
    dist[0] = {0, 0};
    queue<int> que;
    que.emplace(0);

    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto [to, x, y]: G[pos]){
            if(dist[to].first != INF || dist[to].second != INF) continue;
            dist[to] = {dist[pos].first + x, dist[pos].second + y};
            que.emplace(to);
        }
    }
    debug(dist);
    for(int i = 0; i < N; i++) {
        auto [x, y] = dist[i];
        if(x == INF || y == INF) {
            cout << "undecidable" << '\n';
        }else{
            cout << x << " " << y << '\n';
        }
    }
}