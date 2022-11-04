#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n);
    for(int i = 0; i < n+1; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        // 左の敵をまず倒す
        ll Min = min(a[i],b[i]);
        ans += Min;
        a[i] -= Min;
        b[i] -= Min;
        // 余力で右の敵を倒す
        Min = min(a[i+1], b[i]);
        ans += Min;
        a[i+1] -= Min;
        b[i] -= Min;
    }

    cout << ans << endl;
    return 0;
}