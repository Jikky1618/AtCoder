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
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 1; i < N; i++){
        int B; cin >> B, B--;
        G[B].push_back(i);
    }
    debug(G);

    // dp[i] := i番目の社員の給料
    vector<int> dp(N);
    for(int i = N - 1; i >= 0; i--){
        int p_max = -INF, p_min = INF;
        for(auto np: G[i]){
            p_max = max(p_max, dp[np]);
            p_min = min(p_min, dp[np]);
        }
        dp[i] = p_max + p_min + 1;
    }
    debug(dp);
    cout << dp[0] << endl;
}