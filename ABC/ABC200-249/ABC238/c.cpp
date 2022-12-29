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

ll mod_inv(ll a, ll b, ll mod){
    return (a * mod_pow(b, mod - 2, mod)) % mod;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    ll ans = 0;
    for(int i = 1; i <= 18; i++){
        ll cnt = (min((ll)pow(10, i) - 1, N)) - ((ll)pow(10, i - 1)) + 1;
        cnt %= MOD;
        if(cnt < 0) break;
        ans += mod_inv((cnt * (cnt + 1)) % MOD, 2, MOD), ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}