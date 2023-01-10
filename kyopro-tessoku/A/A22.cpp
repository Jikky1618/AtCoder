#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N - 1), B(N - 1);
    for(int i = 0; i < N - 1; i++) cin >> A[i];
    for(int i = 0; i < N - 1; i++) cin >> B[i];

    // dp[i] := マスiまでの合計スコアの最大値
    vector<int> dp(N + 1, -INF);
    dp[1] = 0;

    for(int i = 0; i < N - 1; i++){
        dp[A[i]] = max(dp[A[i]], dp[i+1] + 100);
        dp[B[i]] = max(dp[B[i]], dp[i+1] + 150);
    }

    cout << dp[N] << endl;
}