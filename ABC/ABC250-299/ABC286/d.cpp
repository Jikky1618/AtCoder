#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // dp[i][j] := A[i]円硬貨を使って、j円にすることはできるか
    vector dp(N+1, vector<int>(X+1));
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= X; j++){
            for(int k = 0; k <= B[i]; k++){
                if(j + A[i] * k <= X) dp[i + 1][j + A[i] * k] |= dp[i][j];
            }
        }
    }

    cout << (dp[N][X] ? "Yes" : "No") << endl;
}