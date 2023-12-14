// 小課題 5 まで自力
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int solve1(int N, int W, int D, vector<int>& A) {
    int ans = 0;
    for (int i = 1; i < N; i++) {
        // 駅 i に行き, 戻るを繰り返す
        if (D < 2 * i) break;
        ans++, D -= 2 * i;
    }
    return ans;
}

int solve2(int N, int W, int D, vector<int>& A) {
    int ans = 0;
    // とる個数を全探索する
    for (int i = 1; i <= N - 1; i++) {
        // 後ろから貪欲に回収していく
        int cnt = 0;
        for (int j = i; j > 0; j -= W) {
            // [j - W + 1, j] 駅の荷物を回収
            cnt += 2 * j;
        }
        if (cnt <= D) ans = i;
        if (cnt > D) break;
    }
    return ans;
}

int solve3(int N, int W, int D, vector<int>& A) {
    // ナップサック DP
    // dp[i][j] := i 番目まで見たとき, 移動距離が j のときの最大値
    vector dp(N + 1, vector<int>(D + 1));
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= D; j++) {
            // i 番目を選ぶ
            int nd = j + 2 * i;
            if (nd <= D) {
                dp[i + 1][nd] = max(dp[i + 1][nd], dp[i][j] + A[i]);
            }
            // i 番目を選ばない
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    return dp[N][D];
}

int solve(int N, int W, int D, vector<int>& A) {
    int Dmax = 0;
    // 小課題 2 で求めた距離の最善
    for (int i = N - 1; i > 0; i -= W) Dmax += 2 * i;

    // Dmax 以上なら全ての荷物を回収できる
    if (Dmax <= D) return reduce(A.begin(), A.end());

    // Dmax 未満なら DP で求める (in-place 化)
    // dp[j][k] := i 番目まで見たとき, 移動距離が j で荷物が k のときの最大値
    vector dp(D + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < N; i++) {
        vector nx(D + 1, vector<int>(W + 1, 0));
        for (int j = 0; j <= D; j++) {
            for (int k = 0; k <= W; k++) {
                // i 番目を選んで進む
                if (k + 1 < W) {
                    nx[j][k + 1] = max(nx[j][k + 1], dp[j][k] + A[i]);
                // i 番目を選んで, W になるとき
                }else if (j + 2 * i <= D && k + 1 <= W) {
                    nx[j + 2 * i][0] = max(nx[j + 2 * i][k + 1], dp[j][k] + A[i]);
                }
                // i 番目を選ばない
                nx[j][k] = max(nx[j][k], dp[j][k]);
            }
        }
        swap(dp, nx);
    }

    return dp[D][0];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, W, D;
    cin >> N >> W >> D;
    vector<int> A(N);
    bool task2 = true;
    for (int i = 1; i < N; i++) {
        cin >> A[i];
        if (A[i] != 1) task2 = false;
    }

    if (task2) {
        cout << solve2(N, W, D, A) << endl;
    } else if (W == 1) {
        cout << solve3(N, W, D, A) << endl;
    } else {
        cout << solve(N, W, D, A) << endl;
    }
}