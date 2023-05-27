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
    int X, Y, Z;
    string S;
    cin >> X >> Y >> Z >> S;

    int N = S.size();
    // dp[i][j] := i文字目のキーを打つ時の最短時間(j = 1: Caps Lock)
    vector dp(N + 1, vector<ll>(2, INF));
    dp[0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            // a key
            if((S[i] == 'a' && j == 0) || (S[i] == 'A' && j == 1)){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + X);
            }
            // a + Shift key
            if((S[i] == 'A' && j == 0) || (S[i] == 'a' && j == 1)){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + Y);
            }
            // Caps -> a key
            if((S[i] == 'A' && j == 0) || (S[i] == 'a' && j == 1)){
                dp[i + 1][1 - j] = min(dp[i + 1][1 - j], dp[i][j] + Z + X);
            }
            // Caps -> a + Shift key
            if((S[i] == 'a' && j == 0) || (S[i] == 'A' && j == 1)){
                dp[i + 1][1 - j] = min(dp[i + 1][1 - j], dp[i][j] + Z + Y);
            }
        }
    }

    ll ans = min(dp[N][0], dp[N][1]);
    cout << ans << endl;
}