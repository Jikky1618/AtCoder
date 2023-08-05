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

    // dp[i][j][k] := i 番目まで決めたとき, 総和が j で i 番目を選んだかどうかのフラグが k のとき
    // 操作回数の最小
    vector dp(N + 1, vector(M + 1, vector<int>(2, INF)));
    dp[0][0][1] = 0; // 初期値注意
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            // k: 0 -> 1
            if(j + A[i] <= M) dp[i + 1][j + A[i]][1] = min(dp[i + 1][j + A[i]][1], dp[i][j][0]);
            // k: 1 -> 1
            if(j + A[i] <= M) dp[i + 1][j + A[i]][1] = min(dp[i + 1][j + A[i]][1], dp[i][j][1]);
            // k: 0 -> 0
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0]);
            // k: 1 -> 0 (削除操作が入る)
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1] + 1);
        }
    }

    for(int x = 1; x <= M; x++){
        int ans = min(dp[N][x][0], dp[N][x][1]);
        cout << (ans == INF ? -1 : ans) << endl;
    }
}