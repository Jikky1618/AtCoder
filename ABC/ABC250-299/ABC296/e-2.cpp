#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int LOG = 18;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;

    // ダブリング
    // dp[k][i] := 数字 i から 2^k 回操作をした後の値
    // 2^18 > 2*10^5 なので, 最大限操作すると必ずサイクル上の値となる
    vector dp(LOG + 1, vector<int>(N));
    for(int i = 0; i < N; i++){
        dp[0][i] = A[i];
    }
    for(int k = 0; k < LOG; k++){
        for(int i = 0; i < N; i++){
            dp[k + 1][i] = dp[k][dp[k][i]];
        }
    }

    // 最大限操作したときの値を set に入れる
    set<int> st;
    for(int i = 0; i < N; i++){
        st.insert(dp[LOG][i]);
    }

    cout << st.size() << endl;
}