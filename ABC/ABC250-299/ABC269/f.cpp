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

mint arithmetic_sum(mint f, mint d, mint n){
    // 末項 を求める
    mint l = f + (n - 1) * d;
    // 総和
    mint sum = ((f + l)) * n / 2;
    return sum;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, Q;
    cin >> N >> M >> Q;

    // u 行目の区間 [l, r] の総和と項数を返す
    auto sum = [&](ll u, ll l, ll r) -> pair<mint, int> {
        // l, r が 0 なら調整する
        if((u + l) % 2 == 1) l++;
        if((u + r) % 2 == 1) r--;
        if(r - l < 0) return {0, 0};
        // 項数
        ll n = (r - l) / 2 + 1;
        // 初項
        ll f = (u - 1) * M + l;
        // 初項 f, 項数 n, 公差 2 の総和を求める
        mint s = arithmetic_sum(f, 2, n);
        pair<mint, int> res = {s, n};
        return res;
    };

    // 行の総和が s, 行の項数が sn の区間 [l, r] の総和
    auto sum2 = [&](mint s, ll sn, ll l, ll r) -> mint {
        // 項数
        mint n = (r - l) / 2 + 1;
        // 初項 s, 項数 n, 公差 2 * sn * M の総和を求める
        return arithmetic_sum(s, 2 * sn * M, n);
    };

    auto query = [&](int A, int B, int C, int D) -> mint {
        // 初めの2つの行の総和を考える
        auto [s1, n1] = sum(A, C, D);
        auto [s2, n2] = sum(A + 1, C, D);
        // 区間 [A, B] の行の総和(s1 と偶奇が一致)
        mint s3 = sum2(s1, n1, A, B - (A % 2 != B % 2));
        // 区間 [A + 1, B] の行の総和(s2 と偶奇が一致)
        mint s4 = sum2(s2, n2, A + 1, B - ((A + 1) % 2 != B % 2));
        return (s3 + s4);
    };

    while(Q--){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        cout << query(A, B, C, D) << '\n';
    }
}