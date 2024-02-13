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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // dp[i][S] := i 番目までのサイコロを見て, 出目の合計の集合が S である確率
    const int M = 11;
    vector dp(N + 1, vector<mint>(1 << M));
    dp[0][1 << 0] = 1;
    for (int i = 0; i < N; i++) {
        mint inv = mint(A[i]).inv();
        for (int bit = 0; bit < (1 << M); bit++) {
            if (dp[i][bit] == 0) continue;
            // i 番目のサイコロの出目を 10 以下まで全探索
            for (int j = 1; j <= min(A[i], 10); j++) {
                // 出目 j を選ぶと, 出目の合計の集合 bit は (bit << j) & ((1 << M) - 1) になる
                int nbit = (bit << j) & ((1 << M) - 1);
                // 選ばない場合 bit を合わせる
                dp[i + 1][bit | nbit] += dp[i][bit] * inv;
            }
            // 出目が 10 より大きい場合は選ばない
            if (A[i] > 10) {
                dp[i + 1][bit] += dp[i][bit] * (A[i] - 10) * inv;
            }
        }
    }

    mint ans = 0;
    // 集合 bit に 10 が含まれる場合の確率を全て合わせる
    for (int bit = (1 << (M - 1)); bit < (1 << M); bit++) {
        ans += dp[N][bit];
    }

    cout << ans << '\n';
}