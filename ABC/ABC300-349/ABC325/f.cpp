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

template <class T, class U>
T ceil(T x, U y) {
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T, class U>
T floor(T x, U y) {
    return (x > 0 ? x / y : (x - y + 1) / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> D(N);
    for(int i = 0; i < N; i++) cin >> D[i];
    vector<ll> L(2), C(2), K(2);
    for(int i = 0; i < 2; i++) cin >> L[i] >> C[i] >> K[i];

    // dp[i][j] := i 番目までの区間を見て, センサー 1 を累計 j 個使ったときのセンサー 2 の最小個数
    vector dp(N + 1, vector<int>(K[0] + 1, K[1] + 1));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K[0]; j++){
            // i 番目の区間に使うセンサー 1 の個数を全探索
            for(int k = 0; k <= K[0] - j; k++){
                // 必要なセンサー 2 の個数
                int need = ceil(D[i] - L[0] * k, L[1]);
                dp[i + 1][j + k] = min(dp[i + 1][j + k], dp[i][j] + max(0, need));
            }
        }
    }
    
    ll ans = INF;
    for(int i = 0; i <= K[0]; i++){
        if(K[1] < dp[N][i]) continue; // センサー 2 の個数が足りない場合 continue
        ll cost = C[0] * i + C[1] * dp[N][i];
        ans = min(ans, cost);
    }

    cout << (ans == INF ? -1 : ans) << endl;
}