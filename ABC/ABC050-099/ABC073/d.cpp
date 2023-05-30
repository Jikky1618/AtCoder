#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;
template<class T>
bool warsahll_floyd(vector<vector<pair<int, T>>>& G, vector<vector<ll>>& dist){
    int n = G.size();
    dist = vector(n, vector<ll>(n, INF));
    for(int from = 0; from < n; from++){
        for(auto [to, cost]: G[from]){
            dist[from][to] = cost;
        }
    }
    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int to = 0; to < n; to++){
            for(int from = 0; from < n; from++){
                if(dist[from][i] == INF || dist[i][to] == INF) continue;
                dist[from][to] = min(dist[from][to], dist[from][i] + dist[i][to]);
            }
        }
    }

    // 負の閉路検知
    for(int i = 0; i < n; i++){
        if(dist[i][i] < 0) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    for(int i = 0; i < R; i++) cin >> r[i], r[i]--;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int A, B, C; cin >> A >> B >> C, A--, B--;
        G[A].emplace_back(B, C);
        G[B].emplace_back(A, C);
    }

    vector<vector<ll>> dist;
    warsahll_floyd(G, dist);

    ll ans = INF;
    sort(r.begin(), r.end());
    do{
        ll val = 0;
        for(int i = 0; i < R - 1; i++){
            val += dist[r[i]][r[i + 1]];
        }
        debug(val);
        ans = min(ans, val);
    }while(next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}