#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int LOG = 30;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, D;
    cin >> N >> M >> D;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i], A[i]--;

    // ダブリング
    // dp[k][i] := i 番目の縦線から始めて 2^k 個後にたどり着く縦線
    vector dp(LOG, vector<int>(N));

    vector<int> to(N); // 2^0 回目は普通にシミュレーション
    iota(to.begin(), to.end(), 0);
    for(int i = 0; i < M; i++){
        swap(to[A[i]], to[A[i] + 1]);
    }
    // 初期値
    for(int i = 0; i < N; i++){
        dp[0][to[i]] = i;
    }
    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < N; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }

    for(int i = 0; i < N; i++){
        int pos = i;
        for(int j = 0; j < LOG; j++){
            if((D >> j) & 1){
                pos = dp[j][pos];
            }
        }

        cout << pos + 1 << '\n';
    }
}