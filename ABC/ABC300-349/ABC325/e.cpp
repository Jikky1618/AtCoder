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
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vector D(N, vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> D[i][j];
    }

    // dist[i][j] := 社用車(i = 0) or 電車(i = 1)を使用したときの j の最短時間
    vector dist(2, vector<ll>(N, INF));
    using T = tuple<ll, int, int>;
    // expected, from, use
    priority_queue<T, vector<T>, greater<T>> que;
    dist[0][0] = dist[1][0] = 0;
    que.emplace(0, 0, 0);
    que.emplace(0, 0, 1);
    while(!que.empty()){
        auto [expected, from, use] = que.top();
        que.pop();
        if(dist[use][from] < expected) continue;
        for(int to = 0; to < N; to++){
            if(from == to) continue;
            for(int next_use = 0; next_use < 2; next_use++){
                // 電車 -> 社用車は continue
                if(use == 1 && next_use == 0) continue;
                ll t = (use == 0 ? D[from][to] * A : D[from][to] * B + C);
                if(dist[next_use][to] > dist[use][from] + t){
                    dist[next_use][to] = dist[use][from] + t;
                    que.emplace(dist[next_use][to], to, next_use);
                }
            }
        }
    }
    
    ll ans = min(dist[0][N - 1], dist[1][N - 1]);
    cout << ans << endl;
}