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

const int MOD = 998244353;
using mint = Mint<MOD>;

void solve(int N, string S){
    // dp[i][smaller][j] := i文字目がjのときの場合の数(smaller = 辞書順より小さいか)
    vector dp((N + 1) / 2 + 1, vector(2, vector<mint>(26)));
    dp[0][0][0] = 1;
    for(int i = 0; i < (N + 1) / 2; i++){
        for(int j = 0; j < 26; j++){
            // smaller 1 -> 1 の遷移
            for(int k = 0; k < 26; k++){
                dp[i + 1][1][k] += dp[i][1][j];
            }
            // smaller 0 -> 1 の遷移
            for(int k = 0; k < 26; k++){
                if(k < S[i] - 'A') dp[i + 1][1][k] += dp[i][0][j];
            }
            // smaller 0 -> 0 の遷移
            for(int k = 0; k < 26; k++){
                if(j == S[i] - 'A') dp[i + 1][0][j] += dp[i][0][k];
            }
        }
    }

    // debug(dp);
    mint ans = 0;
    for(int j = 0; j < 26; j++) ans += dp[(N + 1) / 2][1][j];

    // smaller 0 の場合分け
    string p = S;
    for(int i = 0; i < N / 2; i++){
        p[i] = p[N - 1 - i] = S[i];
    }

    if(p <= S) ans += 1;
    cout << ans << "\n";
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while(T--){
        int N;
        string S;
        cin >> N >> S;
        solve(N, S);
    }
}