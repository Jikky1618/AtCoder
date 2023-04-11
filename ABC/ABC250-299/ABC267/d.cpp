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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] := A[i]まででj個選んだときの最大値
    vector dp(N + 1, vector<ll>(M + 1, -INF));
    dp[0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            // A[i]を選ばないとき
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            // A[i]を選ぶとき
            if(j + 1 <= M) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (j + 1) * A[i]);
        }
    }
    
    cout << dp[N][M] << endl;
}