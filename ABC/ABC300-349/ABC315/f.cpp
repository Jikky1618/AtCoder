#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int LOG = 30;

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
    int N;
    cin >> N;
    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;

    // dp[i][c] := i 番目に到達時, 過しなかったチェックポイントの個数が c のときの最短距離
    int M = min(N, LOG);
    vector dp(N, vector<double>(M, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int c = 0; c < M; c++){
            for(int j = 1; j < M; j++){
                if(i + j >= N) break;
                double dist = hypot(P[i].first - P[i + j].first, P[i].second - P[i + j].second);
                int nc = c + j - 1;
                if(nc < M) dp[i + j][nc] = min(dp[i + j][nc], dp[i][c] + dist);
            }
        }
    }

    debug(dp);
    double ans = INF;
    for(int c = 0; c < M; c++){
        ans = min(ans, dp[N - 1][c] + (c > 0 ? 1LL << (c - 1) : 0));
    }

    cout << ans << endl;
}