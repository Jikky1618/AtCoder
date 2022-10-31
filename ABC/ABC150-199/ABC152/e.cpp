#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

vector<pair<ll,ll>> prime_factorize(ll x){
    vector<pair<ll, ll>> factor;
    for (ll p = 2; p * p <= x; p++){
        if (x % p != 0) continue;
        ll exp = 0; // 指数

        // 割れる限り割り続ける
        while (x % p == 0){
            exp++;
            x /= p;
        }

        // その結果を push
        factor.push_back({p, exp});
    }
    if (x != 1) factor.push_back({x, 1});
    return factor;
}

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
    return (a % MOD * mod_pow(b, mod - 2, mod)) % mod;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // num[i] := LCMの素因数iの指数
    map<ll,ll> num;
    for(int i = 0; i < n; i++){
        auto pf = prime_factorize(a[i]);
        for(auto p: pf) num[p.first] = max(num[p.first], p.second);
    }

    ll LCM = 1;
    for(auto p: num){
        for(int i = 0; i < p.second; i++){
            LCM *= p.first;
            LCM %= MOD;
        }
    }

    vector<ll> b(n);
    for(int i = 0; i < n; i++){
        b[i] = mod_div(LCM, a[i], MOD);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += b[i];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}