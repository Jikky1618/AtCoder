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
    string S;
    cin >> S;

    int N = S.size();
    const int LOG = 18;
    // ダブリング
    // dp[k][i] := i 番目のマスから 2^k 回移動した先のマス
    vector dp(LOG, vector<int>(N));
    // 初期値は 2^0 = 1 回移動したときのマス
    for(int i = 0; i < N; i++){
        if(S[i] == 'L'){
            dp[0][i] = i - 1;
        }
        if(S[i] == 'R'){
            dp[0][i] = i + 1;
        }
    }

    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < N; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }

    // 10^100 にすると爆発するため, 2N (十分移動できる偶数)にする
    int K = 2 * N;
    vector<int> ans(N);
    // 各マスの 2N 回後のマスを求める
    for(int i = 0; i < N; i++){
        int pos = i;
        for(int j = 0; j < LOG; j++){
            if((K >> j) & 1) pos = dp[j][pos];
        }
        ans[pos]++;
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N - 1];
    }
}