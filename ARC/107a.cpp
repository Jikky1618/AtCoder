#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll mod_pow(ll a, ll b, ll mod){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll mod_div(ll a, ll b, ll mod){
    return (a * mod_pow(b, mod - 2, mod)) % mod;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,c;
    cin >> a >> b >> c;

    ll sum_a = mod_div((a * (a + 1) % MOD), 2, MOD);
    ll sum_b = mod_div((b * (b + 1) % MOD), 2, MOD);
    ll sum_c = mod_div((c * (c + 1) % MOD), 2, MOD);

    ll ans = sum_a * sum_b % MOD * sum_c % MOD;

    cout << ans << endl;
    return 0;
}