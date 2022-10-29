#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<ll> a(6);
    for(int i = 0; i < 6; i++){
        cin >> a[i];
        a[i] %= MOD;
    }

    ll abc = a[0] * a[1] % MOD * a[2] % MOD;
    ll def = a[3] * a[4] % MOD * a[5] % MOD;
    ll ans = (abc - def + MOD) % MOD;
    cout << ans << endl;
    return 0;
}