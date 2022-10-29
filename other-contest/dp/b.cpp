#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(i - j < 0) break;
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j])); 
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}