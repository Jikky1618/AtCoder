#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // dp[i][j] := i回目の魔法でjダメージ与えたときの魔力の最小値
    vector dp(N + 1, vector<ll>(H + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= H; j++){
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][min(j + A[i], H)] = min(dp[i + 1][min(H, j + A[i])], dp[i + 1][j] + B[i]);
        }
    }

    cout << dp[N][H] << endl;
}