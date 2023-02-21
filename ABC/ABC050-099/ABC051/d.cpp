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
    vector<int> A(M), B(M), C(M);
    vector<vector<int>> G(N, vector<int>(N, INF));
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i] >> C[i], A[i]--, B[i]--;
        G[A[i]][B[i]] = G[B[i]][A[i]] = C[i];
    }
    for(int i = 0; i < N; i++) G[i][i] = 0;

    // フロイドワーシャル法
    for(int i = 0; i < N; i++){
        for(int to = 0; to < N; to++){
            for(int from = 0; from < N; from++){
                if(G[from][i] == INF || G[i][to] == INF) continue;
                G[from][to] = min(G[from][to], G[from][i] + G[i][to]);
            }
        }
    }

    int ans = 0;
    // 全ての辺を全探索
    for(int i = 0; i < M; i++){
        bool flag = true;
        for(int p = 0; p < N; p++){
            for(int q = 0; q < N; q++){
                // 辺iがp-q間の最短経路に含まれているか判定
                if(G[p][q] == G[p][A[i]] + C[i] + G[B[i]][q]) flag = false;
            }
        }
        if(flag) ans++;
    }

    cout << ans << endl;
}