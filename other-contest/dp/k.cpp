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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] := 残り石が i 個のときからスタート時, 先手が勝利するか
    vector<int> dp(K + 1);
    dp[0] = false; // 0 個の石からスタート時, 先手は負ける
    
    for(int i = 0; i <= K; i++){
        for(int j = 0; j < N; j++){
            // 残り i 個の盤面から, 後手に負ける盤面を渡せるか
            // i - A[j] 個の盤面に負ける盤面があれば, それを後手に渡せるので勝てる
            // 逆に負ける盤面に遷移できなければ, 先手は負ける
            if(i - A[j] >= 0) dp[i] |= !dp[i - A[j]];
        }
    }

    cout << (dp[K] ? "First" : "Second") << endl;
}