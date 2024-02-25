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
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }
    int K;
    cin >> K;
    vector<int> C(K);
    for(int i = 0; i < K; i++) cin >> C[i], C[i]--;

    // dist[i][j] := C[i] から C[j] までの最短個数
    vector dist(K, vector<int>(K, INF));
    for(int i = 0; i < K; i++){
        // d[i] := C[i] からの最短距離
        vector<int> d(N, INF);
        queue<int> que;
        d[C[i]] = 0;
        que.emplace(C[i]);
        while(!que.empty()){
            int pos = que.front();
            que.pop();
            for(auto np: G[pos]){
                if(d[np] != INF) continue;
                d[np] = d[pos] + 1;
                que.emplace(np);
            }
        }
        for(int j = 0; j < K; j++){
            dist[i][j] = d[C[j]];
        }
    }

    // dp[S][i] := 今までに訪れた頂点が S で、最後に訪れた頂点が C[i] であるときの最小値
    vector dp(1 << K, vector<int>(K, INF));
    // 初期値が 1 であることに注意
    for(int i = 0; i < K; i++) dp[1 << i][i] = 1;
    for(int bit = 0; bit < (1 << K); bit++){
        for(int i = 0; i < K; i++){
            // S に i が含まれていない場合 continue
            if(!(bit >> i & 1)) continue;
            if(dp[bit][i] == INF) continue;
            for(int j = 0; j < K; j++){
                // S に j が既に含まれている場合 continue
                if(bit >> j & 1) continue;
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + dist[i][j]);
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < K; i++) ans = min(ans, dp[(1 << K) - 1][i]);

    cout << (ans == INF ? -1 : ans) << '\n';
}