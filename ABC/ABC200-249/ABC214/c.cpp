#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> s(n),t(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> t[i];

    // dp[i] := i人目が初めて宝石をもらう時間
    vector<int> dp(n, INF);
    dp[0] = t[0];
    for(int i = 0; i < 2 * n; i++){
        dp[(i + 1) % n] = min(dp[i % n]+s[i % n], t[(i + 1) % n]);
    }

    for(auto &&ans: dp) cout << ans << endl;
    return 0;
}