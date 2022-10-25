#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

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

ll nCr(ll n, ll r, ll mod){
    ll a = 1;
    for(int i = 1; i <= n; i++) a = (a * i) % mod;
    ll b = 1;
    for(int i = 1; i <= r; i++) b = (b * i) % mod;
    for(int i = 1; i <= n - r; i++) b = (b * i) % mod;
    return mod_div(a, b, mod);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll w,h;
    cin >> w >> h;
    cout << nCr(w - 1 + h - 1, h - 1, MOD) << endl;
    return 0;
}