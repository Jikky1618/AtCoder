#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;

    // dp[i][j] := 穴jにいた2^i日後の場所
    vector dp(30, vector<int>(N+1));
    for(int i = 0; i < N; i++) dp[0][i] = A[i];
    for(int d = 0; d < 29; d++){
        for(int i = 0; i < N; i++){
            dp[d+1][i] = dp[d][dp[d][i]];
        }
    }

    while(Q--){
        int X, Y; cin >> X >> Y, X--;
        int ans = X;
        for(int d = 29; d >= 0; d--){
            if((Y >> d) & 1) ans = dp[d][ans];
        }

        cout << ans + 1 << "\n";
    }
}