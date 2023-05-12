#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

ll f(ll N){
    string S = to_string(N);
    int L = S.size();

    // 桁DP
    // dp[i][smaller][j] := i番目の桁まで決めたとき, 4または9が出ている数字の数
    vector dp(L + 1, vector(2, vector<ll>(2)));
    dp[0][0][0] = 1;
    for(int i = 0; i < L; i++){
        for(int smaller = 0; smaller < 2; smaller++){
            for(int j = 0; j < 2; j++){
                for(int d = 0; d <= (smaller ? 9 : S[i] - '0'); d++){
                    dp[i + 1][smaller | (d < (S[i] - '0'))][j | (d == 4) | (d == 9)] += dp[i][smaller][j];
                }
            }
        }
    }

    return dp[L][0][1] + dp[L][1][1];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B;
    cin >> A >> B;

    ll ans = f(B) - f(A - 1);
    cout << ans << endl;
}