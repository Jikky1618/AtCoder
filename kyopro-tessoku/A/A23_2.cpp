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
    vector A(M, vector<int>(N));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    // V[i] := A[i]のチケットでどの品物が無料になるかの集合を計算
    vector<int> V(M);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j] == 1) V[i] |= (1 << j);
        }
    }

    // dp[i][S] := i番目までのクーポンで無料でもらえる品物の集合Sになるための最小枚数
    vector dp(M + 1, vector<int>(1 << N, INF));
    dp[0][0] = 0;
    for(int i = 0; i < M; i++){
        for(int bit = 0; bit < (1 << N); bit++){
            dp[i + 1][bit] = min(dp[i + 1][bit], dp[i][bit]);
            dp[i + 1][bit | V[i]] = min(dp[i + 1][bit | V[i]], dp[i][bit] + 1);
        }
    }

    cout << (dp[M][(1 << N) - 1] == INF ? -1 : dp[M][(1 << N) - 1]) << endl;
}