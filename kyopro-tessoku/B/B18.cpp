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
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] := カードiまで選んだとき、合計をjにすることはできるか
    vector dp(N + 1, vector<int>(S + 1));
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= S; j++){
            dp[i + 1][j] |= dp[i][j];
            if(j + A[i] <= S) dp[i + 1][j + A[i]] |= dp[i][j];
        }
    }

    if(!dp[N][S]){
        cout << -1 << endl;
        return 0;
    }

    // 経路復元
    vector<int> ans;
    int val = S;
    for(int i = N - 1; i >= 0; i--){
        if(dp[i][val] == 0){
            ans.push_back(i + 1);
            val -= A[i];
        }
    }

    reverse(ans.begin(), ans.end());
    int K = ans.size();
    cout << K << endl;
    for(int i = 0; i < K; i++){
        cout << ans[i] << " \n"[i == K - 1];
    }
}