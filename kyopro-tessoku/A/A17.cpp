#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 2; i < n; i++) cin >> b[i];

    // dp
    vector<int> dp(n, INF);
    dp[0] = 0;
    dp[1] = a[1];
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i]);
    }

    vector<int> ans;
    int pos = n - 1;
    while(1){
        ans.push_back(pos);
        if(pos == 0) break;
        if(dp[pos - 1] + a[pos] == dp[pos]) pos -= 1;
        else pos -= 2;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(auto &&i: ans) cout << i + 1 << " ";
    cout << endl;
    return 0;
}