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
    int N, M;
    cin >> N >> M;
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    set<pair<int, int>> st;
    for(int i = 0; i < M; i++){
        int X, Y; cin >> X >> Y;
        st.insert({X, Y});
    }

    // dp[i][j][k] := i回(A, B), j回(C, D), k回(E, F)回移動したときの経路数
    vector dp(N + 1, vector(N + 1, vector<mint>(N + 1)));
    dp[0][0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(i + j + k > N) break;
                ll x = i * A + j * C + k * E;
                ll y = i * B + j * D + k * F;
                
                // +(A, B) に移動
                if(st.find({x + A, y + B}) == st.end()){
                    dp[i + 1][j][k] += dp[i][j][k];
                }
                // +(C, D) に移動
                if(st.find({x + C, y + D}) == st.end()){
                    dp[i][j + 1][k] += dp[i][j][k];
                }
                // +(E, F) に移動
                if(st.find({x + E, y + F}) == st.end()){
                    dp[i][j][k + 1] += dp[i][j][k];
                }
            }
        }
    }

    mint ans = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N - i; j++){
            int k = N - i - j;
            ans += dp[i][j][k];
        }
    }

    cout << ans << endl;
}