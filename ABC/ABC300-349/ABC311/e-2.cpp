#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// able のみで構成されたマス(i, j)を右下にしたときの最大の正方形の大きさを返す
template <class T>
vector<vector<int>> largest_square(const vector<vector<T>>& V, T able = 1) {
    int H = V.size(), W = V.front().size();
    // dp[i][j] := (i, j) を右下とした正方形の最大の大きさ
    vector dp(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // (i, j) が使えない場合は 0
            if (V[i][j] != able) {
                continue;
            }
            // 上端、左端の場合は最大 1
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
                continue;
            }
            // 上、左、左上から貰う DP で遷移
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    }
    return dp;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }

    auto dp = largest_square(A, 0);
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            ans = max(ans, dp[i][j] * dp[i][j]);
        }
    }

    cout << ans << endl;
}