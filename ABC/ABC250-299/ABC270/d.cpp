#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for(int i = 0; i < K; i++) cin >> A[i];

    // dp[i] := 石の個数が残りi個のときの取り除ける最大値
    vector<int> dp(N + 1);
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < K; j++){
            if(i - A[j] >= 0) dp[i] = max(dp[i], i - dp[i - A[j]]);
        }
    }

    cout << dp[N] << endl;
    return 0;
}