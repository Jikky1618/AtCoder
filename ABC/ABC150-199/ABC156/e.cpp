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

const int MOD = 1e9 + 7;
using mint = modint<MOD>;

template <class T>
struct Binomial {
    vector<T> _fact, _inv, _inv_fact;
    constexpr Binomial(int n) noexcept : _fact(n, 1), _inv(n), _inv_fact(n) {
        _fact.assign(n, 1), _inv.assign(n, 1), _inv_fact.assign(n, 1);
        for (int i = 2; i < n; i++) {
            _fact[i] = _fact[i - 1] * i;
            _inv[i] = -_inv[MOD % i] * (MOD / i);
            _inv_fact[i] = _inv_fact[i - 1] * _inv[i];
        }
    }
    constexpr T perm(int n, int r) const noexcept {
        if (r < 0 || n - r < 0) return 0;
        return _fact[n] * _inv_fact[n - r];
    }
    constexpr T com(int n, int r) const noexcept {
        if (n < r || n < 0 || r < 0) return 0;
        return _fact[n] * _inv_fact[r] * _inv_fact[n - r];
    }

    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return _fact[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return _inv[n];
    }
    constexpr T inv_fact(int n) const noexcept {
        if (n < 0) return 0;
        return _inv_fact[n];
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, K;
    cin >> N >> K;

    mint ans = 0;
    // 空いた部屋の個数を全探索, 上限は min(K, N - 1)
    Binomial<mint> binom(2 * N);
    for (int i = 0; i <= min(K, N - 1); i++) {
        // このとき, 空いた部屋の個数が i 個のとき
        // 1 人以上いる部屋の組合せ: com(N, i)
        // 1 人以上いる部屋 N - i 個から N - i 人を重複有り(必ず 1 つ以上選ぶ)の組合せ
        // 各部屋必ず 1 つ選ばれるので, N - i 個の部屋から残りの N - (N - i) 人を選ぶ重複組合せ
        ll remain = N - (N - i);
        ans += binom.com(N, i) * binom.com(N - i + remain - 1, remain);
    }

    cout << ans << '\n';
}