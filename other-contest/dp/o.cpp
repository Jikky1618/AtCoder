#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

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
    vector A(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }

    // dp[S] := 男性は |S| 人まで見たとき, マッチング済みの女性の集合が S であるようなマッチングの総数
    vector<ll> dp(1 << N);
    dp[0] = 1;
    for(int bit = 0; bit < (1 << N); bit++){
        // 男性は既に |S| 人見ている
        int i = __builtin_popcount(bit);
        for(int j = 0; j < N; j++){
            // 既に女性 j がマッチング済みなら continue
            if((bit >> j) & 1) continue;
            // 男性 i と女性 j がマッチングできるなら, dp[bit | (1 << j)] に加算
            if(A[i][j]) dp[bit | (1 << j)] += dp[bit], dp[bit | (1 << j)] %= MOD;
        }
    }

    cout << dp[(1 << N) - 1] << endl;
}