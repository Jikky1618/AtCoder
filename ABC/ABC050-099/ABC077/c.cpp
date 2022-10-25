#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    // 中部パーツBを全探索
    for(int i = 0; i < n; i++){
        ll a_cnt = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll c_cnt = n - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
        ans += a_cnt * c_cnt;
    }

    cout << ans << endl;
    return 0;
}