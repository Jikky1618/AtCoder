#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 累積和
    vector<ll> s(n+1);
    for(int i = 0; i < n; i++) s[i+1] = s[i] + a[i];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i] * ((s[n] - s[i+1]) % MOD);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}