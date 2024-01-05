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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] := A の区間が [i, j) からスタートしたときの得点の差
    vector dp(N + 1, vector<ll>(N + 1));
    // 初期値は A[i, i) = 0
    for(int i = 0; i < N; i++) dp[i][i] = 0;
    
    // 長さ len が短い順に更新
    for(int len = 1; len <= N; len++){
        for(int left = 0; left + len <= N; left++){
            int right = left + len;
            // [left, right) から A[left] を取り, [left + 1, right) に遷移
            // [left, right) から A[right - 1] を取り, [left, right - 1) に遷移
            // この 2 手の最大値 / 最小値を取る(貰う dp)
            // 先手
            if(N % 2 == len % 2){
                dp[left][right] = max(dp[left + 1][right] + A[left], dp[left][right - 1] + A[right - 1]);
            // 後手
            }else{
                dp[left][right] = min(dp[left + 1][right] - A[left], dp[left][right - 1] - A[right - 1]);
            }
        }
    }
    
    cout << dp[0][N] << endl;
}