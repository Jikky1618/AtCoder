#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll mod_pow(ll a, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;
    ll ans = (mod_pow(10, N, MOD) - mod_pow(9, N, MOD) - mod_pow(9, N, MOD) + mod_pow(8, N, MOD));
    ans %= MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}