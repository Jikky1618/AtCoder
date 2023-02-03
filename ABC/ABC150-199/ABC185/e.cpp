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
    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    // dp[i][j] := A_i, B_jまでの編集距離
    vector dp(N + 1, vector<int>(M + 1, INF));
    for(int i = 0; i <= N; i++) dp[i][0] = i;
    for(int j = 0; j <= M; j++) dp[0][j] = j;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i + 1 <= N) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if(j + 1 <= M) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            if(i + 1 <= N && j + 1 <= M) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (A[i] == B[j] ? 0 : 1));
        }
    }

    cout << dp[N][M] << endl;
}