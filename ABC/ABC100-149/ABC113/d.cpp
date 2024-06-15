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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W, K;
    cin >> H >> W >> K, K--;

    // j 列目に type が t の棒を設置したときの j 列目の組合せ
    auto solve = [&](int j, int t) -> mint {
        mint res = 0;
        for (int bit = 0; bit < (1 << (W - 1)); bit++) {
            vector<bool> line(W - 1);
            for (int i = 0; i < W - 1; i++) {
                if ((bit >> i) & 1) line[i] = true;
            }
            // 隣接している場所に棒がないか判定
            bool ng = false;
            for (int i = 0; i < W - 1 - 1; i++) {
                if (line[i] && line[i + 1]) ng = true;
            }
            // t = 0 なら line[j - 1] が true
            if (t == 0 && !line[j - 1]) ng = true;
            // t = 1 なら line[j - 1] と line[j] が false
            if (t == 1 && ((j - 1 >= 0 && line[j - 1]) || (j < W - 1 && line[j]))) ng = true;
            // t = 2 なら line[j] が true
            if (t == 2 && !line[j]) ng = true;

            if (!ng) res++;
        }
        return res;
    };

    // dp[i][j] := 1 列目からスタートして i 行目, j 列目にいる組合せの数
    vector dp(H + 1, vector<mint>(W));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // 左に移動
            if (0 <= j - 1) dp[i + 1][j - 1] += dp[i][j] * solve(j, 0);
            // 移動しない
            dp[i + 1][j] += dp[i][j] * solve(j, 1);
            // 右に移動
            if (j + 1 < W) dp[i + 1][j + 1] += dp[i][j] * solve(j, 2);
        }
    }

    debug(dp);
    cout << dp[H][K] << '\n';
}