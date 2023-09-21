#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    vector V(N, vector<int>(3));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++) cin >> V[i][j];
    }

    // dp[i][j] := i 日目に活動 j を選んだときの幸福度の総和の最大値
    // 活動 A, B, C を 1, 2, 3 に対応させる
    vector dp(N + 1, vector<int>(3));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            // i + 1 日目に行う活動を全探索
            for(int k = 0; k < 3; k++){
                // i 日目と i + 1 日目の活動は同じにできない
                if(j == k) continue;
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + V[i][k]);
            }
        }
    }

    int ans = *max_element(dp[N].begin(), dp[N].end());
    cout << ans << endl;
}