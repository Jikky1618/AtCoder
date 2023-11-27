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

const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

void test() {
    // 実験
    int H = 3, W = 5, K = 5;
    int x = 1, y = 2;

    vector dp(K + 1, vector(H, vector(W, 0)));
    dp[0][x][y] = 1;
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                // 上下左右に移動
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    while (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                        dp[k + 1][nx][ny] += dp[k][i][j];
                        nx += dx[d];
                        ny += dy[d];
                    }
                }
            }
        }
    }
    for (int k = 0; k <= K; k++) debug(k, dp[k]);
    return;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    mint H, W;
    int K;
    cin >> H >> W >> K;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2, x1--, y1--, x2--, y2--;

    // (x1, y1) を中心と呼ぶ
    // 中心, 行が中心と同じ, 列が中心と同じ, その他の 4 つの領域に分け遷移
    vector<mint> dp(4);
    dp[0] = 1;
    for (int i = 0; i < K; i++) {
        vector<mint> nx(4);
        // 中心を遷移
        nx[0] = dp[1] * (W - 1) + dp[2] * (H - 1);
        // 行中心を遷移
        nx[1] = dp[0] + dp[1] * (W - 2) + dp[3] * (H - 1);
        // 列中心を遷移
        nx[2] = dp[0] + dp[2] * (H - 2) + dp[3] * (W - 1);
        // その他を遷移
        nx[3] = dp[1] + dp[2] + dp[3] * (H + W - 4);
        swap(dp, nx);
    }
    debug(dp);
    // (x2, y2) がどの領域にいるかで場合分け
    if (x1 == x2 && y1 == y2) {
        cout << dp[0] << endl;
    } else if (x1 == x2) {
        cout << dp[1] << endl;
    } else if (y1 == y2) {
        cout << dp[2] << endl;
    } else {
        cout << dp[3] << endl;
    }
}