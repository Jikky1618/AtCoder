#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<int MOD> struct modint {
    ll val;
    constexpr modint(ll x = 0): val(x % MOD) {
        if(val < 0) val += MOD;
    }
    constexpr int mod() const { return MOD; }
    constexpr modint operator + () const {
        return modint(val);
    }
    constexpr modint operator - () const {
        return modint(MOD - val);
    }
    constexpr modint& operator++() {
        return (*this) += 1;
    }
    constexpr modint& operator--() {
        return (*this) -= 1;
    }
    constexpr modint operator++(int) {
        modint x = (*this); ++(*this);
        return x;
    }
    constexpr modint operator--(int) {
        modint x = (*this); --(*this);
        return x;
    }
    constexpr modint operator + (const modint& x) const {
        return modint(*this) += x;
    }
    constexpr modint operator - (const modint& x) const {
        return modint(*this) -= x;
    }
    constexpr modint operator * (const modint& x) const {
        return modint(*this) *= x;
    }
    constexpr modint operator / (const modint& x) const {
        return modint(*this) /= x;
    }
    constexpr modint& operator += (const modint& x) {
        if((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator -= (const modint& x) {
        if((val += MOD - x.val) >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator *= (const modint& x) {
        (val *= x.val) %= MOD;
        return *this;
    }
    constexpr modint& operator /= (const modint& x){
        return (*this) *= x.inv();
    }
    constexpr bool operator == (const modint& x) const {
        return this->val == x.val;
    }
    constexpr bool operator != (const modint& x) const {
        return this->val != x.val;
    }
    constexpr modint pow(ll t) const {
        if(t == 0) return 1;
        modint x = *this, res = 1;
        while(t > 0){
            if(t & 1) res *= x;
            x *= x;
            t >>= 1;
        }
        return res;
    }
    constexpr modint inv() const {
        ll a = val, b = MOD, u = 1, v = 0;
        while(b > 0){
            ll t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    friend constexpr istream& operator >> (istream& is, modint& x) {
        is >> x.val;
        x.val %= MOD;
        if(x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream& os, const modint& x) {
        return os << x.val;
    }
};

const int MOD = 1e9 + 7;
using mint = modint<MOD>;

vector<pair<ll, ll>> prime_factorize(ll n){
    vector<pair<ll, ll>> factor;
    for (ll p = 2; p * p <= n; p++){
        if (n % p != 0) continue;
        ll exp = 0;
        while (n % p == 0){
            exp++;
            n /= p;
        }
        factor.push_back({p, exp});
    }
	if (n != 1) factor.push_back({n, 1});
	return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B;
    cin >> A >> B;

    // B! の倍数: (1*2*...*B)k
    // 求めたい数 x = (1*2*...*A) % (1*2*...*B)k = 0
    // = ((B+1)*...*A) % k = 0 
    // ((B+1)*...*A) の約数の個数が答え
    map<ll, ll> mp;
    for(int k = B + 1; k <= A; k++){
        auto pf = prime_factorize(k);
        for(auto [p, e]: pf){
            mp[p] += e;
        }
    }

    debug(mp);
    mint ans = 1;
    for(auto [key, val]: mp){
        ans *= (val + 1);
    }

    cout << ans << endl;
}