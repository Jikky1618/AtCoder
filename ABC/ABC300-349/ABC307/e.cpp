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

const int MOD = 998244353;
using mint = modint<MOD>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;

    // dp[i][j] := i人目まで決めたとき, i人目に割り当てた数が1人目と(j?同じ:違う)ものの個数
    vector dp(N, vector<mint>(2));
    dp[0][1] = M;
    for(int i = 0; i < N - 1; i++){
        dp[i + 1][1] += dp[i][0];
        dp[i + 1][0] += dp[i][1] * (M - 1);
        dp[i + 1][0] += dp[i][0] * (M - 2);
    }

    cout << dp[N - 1][0] << endl;
}