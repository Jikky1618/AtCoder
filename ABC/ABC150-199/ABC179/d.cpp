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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> L(K), R(K);
    for(int i = 0; i < K; i++) cin >> L[i] >> R[i];

    vector<pair<int, int>> P(K);
    for(int i = 0; i < K; i++) P[i] = {L[i], R[i]};

    // dp[i] := i に到達するまでのパターン数
    // sdp := dp の累積和
    vector<mint> dp(N), sdp(N + 1);
    dp[0] = sdp[1] = 1;
    for(int i = 1; i < N; i++){
        for(auto e: P){
            int left = max(0, i - e.second);
            int right = max(0, i - e.first + 1);
            dp[i] += sdp[right] - sdp[left];
        }
        sdp[i + 1] = sdp[i] + dp[i];
    }

    debug(dp);
    cout << dp[N - 1] << endl;
}