#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A, B;
    cin >> N >> A >> B;

    // dp[i] := 石の数が残りi個のとき、勝つかどうか
    vector<int> dp(N+1);

    for(int i = 0; i <= N; i++){
        if(i >= A && dp[i - A] == 0) dp[i] = 1;
        else if(i >= B && dp[i - B] == 0) dp[i] = 1;
        else dp[i] = 0;
    }

    cout << (dp[N] == 1 ? "First" : "Second") << endl;
}