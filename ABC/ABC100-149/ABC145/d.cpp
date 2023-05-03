#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<int MOD> struct Mint {
    ll val;
    constexpr Mint(ll x = 0): val(x % MOD) {
        if(val < 0) val += MOD;
    }
    constexpr int getmod() const { return MOD; }
    constexpr Mint operator + () const {
        return Mint(val);
    }
    constexpr Mint operator - () const {
        return Mint(MOD - val);
    }
    constexpr Mint operator + (const Mint& x) const {
        return Mint(*this) += x;
    }
    constexpr Mint operator - (const Mint& x) const {
        return Mint(*this) -= x;
    }
    constexpr Mint operator * (const Mint& x) const {
        return Mint(*this) *= x;
    }
    constexpr Mint operator / (const Mint& x) const {
        return Mint(*this) /= x;
    }
    constexpr Mint& operator += (const Mint& x) {
        if((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    constexpr Mint& operator -= (const Mint& x) {
        if((val += MOD - x.val) >= MOD) val -= MOD;
        return *this;
    }
    constexpr Mint& operator *= (const Mint& x) {
        (val *= x.val) %= MOD;
        return *this;
    }
    constexpr Mint& operator /= (const Mint& x){
        return (*this) *= x.inv();
    }
    constexpr bool operator == (const Mint& x) const {
        return this->val == x.val;
    }
    constexpr bool operator != (const Mint& x) const {
        return this->val != x.val;
    }
    constexpr Mint pow(ll t) const {
        if(t == 0) return 1;
        Mint x = pow(t >> 1);
        x *= x;
        if(t & 1) x *= *this;
        return x;
    }
    constexpr Mint inv() const {
        ll a = val, b = MOD, u = 1, v = 0;
        while(b > 0){
            ll t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return Mint(u);
    }
    friend constexpr istream& operator >> (istream& is, Mint& x) {
        is >> x.val;
        x.val %= MOD;
        if(x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream& os, const Mint& x) {
        return os << x.val;
    }
};

const int MOD = 1e9 + 7;
using mint = Mint<MOD>;

template<class T>
T binomial(ll n, ll r){
    T res = 1;
    r = min(r, n - r);
    for(int i = 0; i < r; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int X, Y;
    cin >> X >> Y;

    // 操作回数
    int A = (2 * Y - X) / 3, B = (2 * X - Y) / 3;
    // A, Bがそれぞれ整数解かどうか
    bool flag = (0 <= A && 0 <= B && (2 * Y - X) % 3 == 0 && (2 * X - Y) % 3 == 0);
    // 出力
    cout << (flag ? binomial<mint>(A + B, A) : 0) << endl;
}