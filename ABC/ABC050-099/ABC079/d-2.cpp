#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int INF = (1 << 30) - 1;
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
    int H, W;
    cin >> H >> W;
    vector c(10, vector<int>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) cin >> c[i][j];
    }
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }

    // グラフに変える
    vector<vector<pair<int, int>>> G(10);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            G[i].emplace_back(j, c[i][j]);
        }
    }

    vector<vector<ll>> dist;
    warsahll_floyd(G, dist);

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == -1 || A[i][j] == 1) continue;
            ans += dist[A[i][j]][1];
        }
    }

    cout << ans << endl;
}