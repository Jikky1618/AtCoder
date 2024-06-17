#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <int MOD>
struct modint {
    ll val;
    constexpr modint(ll x = 0) : val(x % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int mod() const { return MOD; }
    constexpr modint operator+() const { return modint(val); }
    constexpr modint operator-() const { return modint(MOD - val); }
    constexpr modint& operator++() { return (*this) += 1; }
    constexpr modint& operator--() { return (*this) -= 1; }
    constexpr modint operator++(int) {
        modint x = (*this);
        ++(*this);
        return x;
    }
    constexpr modint operator--(int) {
        modint x = (*this);
        --(*this);
        return x;
    }
    constexpr modint operator+(const modint& x) const { return modint(*this) += x; }
    constexpr modint operator-(const modint& x) const { return modint(*this) -= x; }
    constexpr modint operator*(const modint& x) const { return modint(*this) *= x; }
    constexpr modint operator/(const modint& x) const { return modint(*this) /= x; }
    constexpr modint& operator+=(const modint& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator-=(const modint& x) {
        if ((val += MOD - x.val) >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator*=(const modint& x) {
        (val *= x.val) %= MOD;
        return *this;
    }
    constexpr modint& operator/=(const modint& x) { return (*this) *= x.inv(); }
    constexpr bool operator==(const modint& x) const { return this->val == x.val; }
    constexpr bool operator!=(const modint& x) const { return this->val != x.val; }
    constexpr modint pow(ll t) const {
        if (t == 0) return 1;
        modint x = *this, res = 1;
        while (t > 0) {
            if (t & 1) res *= x;
            x *= x;
            t >>= 1;
        }
        return res;
    }
    constexpr modint inv() const {
        ll a = val, b = MOD, u = 1, v = 0;
        while (b > 0) {
            ll t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    friend constexpr istream& operator>>(istream& is, modint& x) {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator<<(ostream& os, const modint& x) { return os << x.val; }
};

const int MOD = 998244353;
using mint = modint<MOD>;

template <class T>
struct Binomial {
    vector<T> fact_, inv_, inv_fact_;
    constexpr Binomial(int n) noexcept : fact_(n, 1), inv_(n), inv_fact_(n) {
        fact_.assign(n, 1), inv_.assign(n, 1), inv_fact_.assign(n, 1);
        for (int i = 2; i < n; i++) {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = -inv_[MOD % i] * (MOD / i);
            inv_fact_[i] = inv_fact_[i - 1] * inv_[i];
        }
    }
    constexpr T perm(int n, int r) const noexcept {
        if (r < 0 || n - r < 0) return 0;
        return fact_[n] * inv_fact_[n - r];
    }
    constexpr T com(int n, int r) const noexcept {
        if (n < r || n < 0 || r < 0) return 0;
        return fact_[n] * inv_fact_[r] * inv_fact_[n - r];
    }
    constexpr T hom(int n, int r) const noexcept {
        if (n == 0 && r == 0) return 1;
        return com(n + r - 1, r);
    };
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T inv_fact(int n) const noexcept {
        if (n < 0) return 0;
        return inv_fact_[n];
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;
    int N = S.size();
    // 各文字に使用されている回数を数える
    const int M = 26;
    vector<int> cnt(M);
    for (auto c : S) cnt[c - 'a']++;

    // dp[j] := Alphabet の i 文字目まで見て, j 文字使用したときの場合の数
    vector<mint> dp(N + 1);
    dp[0] = 1;

    Binomial<mint> b(N + 1);
    for (int i = 0; i < M; i++) {
        for (int j = N; j >= 0; j--) {
            // Alphabet の i 文字目を k 個使用する
            // k 個の並べ替えの組合せが重複するので, k! で割る
            for (int k = 1; j + k <= N && k <= cnt[i]; k++) {
                dp[j + k] += dp[j] * b.inv_fact(k);
            }
        }
    }

    // j 文字使用したときの並べ替えの組合せ j! 通りを掛ける
    mint ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[i] * b.fact(i);
    }

    cout << ans << '\n';
}