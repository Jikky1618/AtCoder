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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;
    
    // ダブリング
    // dp[k][i] := 穴 i にいたアリの 2^k 日後の場所
    vector dp(LOG, vector<int>(N));
    // 初期値
    dp[0] = A;
    // 遷移
    for(int k = 0; k < LOG - 1; k++){
        for(int i = 0; i < N; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }

    while(Q--){
        int X, Y; cin >> X >> Y, X--;
        int pos = X;
        for(int i = 0; i < LOG; i++){
            if((Y >> i) & 1){
                pos = dp[i][pos];
            }
        }

        cout << pos + 1 << '\n';
    }
}