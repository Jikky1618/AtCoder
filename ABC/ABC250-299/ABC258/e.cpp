#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int LOG = 40;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q, X;
    cin >> N >> Q >> X;
    vector<int> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];

    // 円環上は 2 周させる -> 累積和
    vector<ll> acc(2 * N + 1);
    for(int i = 0; i < N; i++) acc[i + 1] = acc[i] + W[i];
    for(int i = 0; i < N; i++) acc[N + i + 1] = acc[N + i] + W[i];

    // X < acc[N] の場合に帰着させる
    ll X2 = X % acc[N];
    ll cycle_cnt = X / acc[N];

    auto check = [&](int mid, int i) -> bool {
        return X2 <= acc[mid] - acc[i];
    };

    // C[i] := i 番目から新しい箱に入れたとき, 何個目に総和が X 以上になるか
    // = 箱に何個入れれるか
    vector<int> C(N);
    // 初めて総和が X2 以上になる index を二分探索
    for(int i = 0; i < N; i++){
        int ok = 2 * N, ng = i - 1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            (check(mid, i) ? ok : ng) = mid;
        }
        C[i] = cycle_cnt * N + ok - i;
    }

    // ダブリング
    // dp[k][i] := i 番目から初めたとき, 2^k 番目に蓋をされた箱の最後にいれるじゃがいもの番号
    vector dp(LOG, vector<int>(N));
    // 初期化
    for(int i = 0; i < N; i++){
        dp[0][i] = (i + C[i]) % N;
    }
    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < N; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }

    while(Q--){
        ll K;
        cin >> K, K--;
        int pos = 0;
        for(int i = 0; i < LOG; i++){
            if((K >> i) & 1){
                pos = dp[i][pos];
            }
        }

        cout << C[pos] << '\n';
    }
}