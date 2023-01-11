#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector A(M, vector<int>(N));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }

    // dp[i][S] := i番目までのクーポンで、集合Sを満たすことができるクーポンの最小枚数
    vector dp(M+1, vector<int>((1 << N), INF));
    dp[0][0] = 0;
    for(int i = 0; i < M; i++){
        for(int bit = 0; bit < (1 << N); bit++){
            vector<int> free(N); // 既に無料の品物
            for(int j = 0; j < N; j++){
                if((bit >> j) & 1) free[j] = 1;
            }

            // チケットiを選んだときの整数表現vを計算
            int v = 0;
            for(int j = 0; j < N; j++){
                if(free[j] || A[i][j] == 1) v += (1 << j);
            }

            // 遷移
            dp[i+1][bit] = min(dp[i+1][bit], dp[i][bit]);
            dp[i+1][v] = min(dp[i+1][v], dp[i][bit] + 1);
        }
    }

    cout << (dp[M][(1 << N) - 1] == INF ? -1 : dp[M][(1 << N) - 1]) << endl;
}