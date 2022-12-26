#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int N = S.size();
    vector<vector<int>> dp(N + 1, vector<int>(3, -1));
    dp[0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= min(i, 2); j++){
            string s = S.substr(i - j, j);
            for(int add = 1; add <= 2; add++){
                if(S.substr(i, add) == s) continue;
                if(i+add<=N) dp[i+add][add] = max(dp[i+add][add], dp[i][j]+1);
            }
        }
    }

    cout << max(dp[N][1], dp[N][2]) << endl;
    return 0;
}