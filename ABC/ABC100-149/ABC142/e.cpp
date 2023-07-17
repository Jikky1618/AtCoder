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
    vector<int> A(M);
    vector<int> S(M); // S[i] := 鍵 i が開けれる宝箱の集合
    for(int i = 0; i < M; i++){
        int B; cin >> A[i] >> B;
        for(int j = 0; j < B; j++){
            int c; cin >> c, c--;
            S[i] += (1 << c);
        }
    }

    // dp[i][j] := i 個目までの鍵を見たとき, 開けれる宝箱の集合を j とした費用の最小値
    vector dp(M + 1, vector<int>(1 << N, INF));
    dp[0][0] = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < (1 << N); j++){
            // i 個目を選ぶ
            dp[i + 1][j | S[i]] = min(dp[i + 1][j | S[i]], dp[i][j] + A[i]);
            // i 個目を選ばない
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }

    cout << (dp[M][(1 << N) - 1] == INF ? -1 : dp[M][(1 << N) - 1]) << endl;
}