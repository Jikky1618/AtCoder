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

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> X(N), Y(N), Z(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> Z[i];

    int MAX = 0;
    for(int i = 0; i < N; i++) MAX += Z[i];

    // dp[i][j] := i 番目の区まで見て、獲得した議席が j のとき鞍替えさせた人数の最小
    vector dp(N + 1, vector<ll>(MAX + 1, INF));
    dp[0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= MAX; j++){
             // i 番目の区に勝利する最少人数
            ll cnt = (X[i] < Y[i] ? ceil(Y[i] - X[i], 2) : 0);
            // 勝利する場合
            if(j + Z[i] <= MAX){
                dp[i + 1][j + Z[i]] = min(dp[i + 1][j + Z[i]], dp[i][j] + cnt);
            }
            // 敗北する場合
            if(Y[i] > X[i]){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }
    }
    debug(dp);
    ll ans = INF;
    for(int i = ceil(MAX, 2); i <= MAX; i++){
        ans = min(ans, dp[N][i]);
    }

    cout << ans << endl;
}