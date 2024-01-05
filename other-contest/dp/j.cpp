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

    vector<int> cnt(3);
    for(int i = 0; i < N; i++) cnt[A[i] - 1]++;

    // dp[i][j][k] := 残り 1 貫が i 皿, 2 貫が j 皿, 3 貫が k 皿のときの期待値
    vector dp(N + 1, vector(N + 1, vector<double>(N + 1)));
    // メモ化再帰
    auto memo = [&](auto&& self, int i, int j, int k) -> double {
        if(dp[i][j][k] != 0.0) return dp[i][j][k];
        if(i == 0 && j == 0 && k == 0) return 0.0; // 自明な場合

        // 遷移は式変形しまくって導出
        double res = 1 - double(i + j + k) / N;
        if(i > 0){
            res += (self(self, i - 1, j, k) + 1) * i / N; // 1 貫を取る
        }
        if(j > 0){
            res += (self(self, i + 1, j - 1, k) + 1) * j / N; // 2 貫を取る
        }
        if(k > 0){
            res += (self(self, i, j + 1, k - 1) + 1) * k / N; // 3 貫を取る
        }
        res *= double(N) / (i + j + k);
        return dp[i][j][k] = res;
    };

    double ans = memo(memo, cnt[0], cnt[1], cnt[2]);
    cout << ans << endl;
}