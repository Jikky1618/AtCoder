#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] := カードiまでにいくつか選んだ時、合計をjにできるか
    vector dp(N+1, vector<int>(S+1));
    dp[0][0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= S; j++){
            dp[i + 1][j] |= dp[i][j];
            if(j + A[i] <= S) dp[i + 1][j + A[i]] |= dp[i][j];
        }
    }

    cout << (dp[N][S] ? "Yes" : "No") << endl;
    return 0;
}