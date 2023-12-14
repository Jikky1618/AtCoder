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

const int MOD = 1e9 + 7;
using mint = modint<MOD>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    // dp[i][j][k][l] := i 文字目まで見たとき, 一つ前が j, 二つ前が k, 三つ前が l であるような文字列で条件を満たす文字列
    // empty: 0, A: 1, C: 2, G: 3, T: 4
    vector dp(N + 1, vector(5, vector(5, vector<mint>(5))));
    dp[0][0][0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                for(int l = 0; l < 5; l++){
                    // 次の文字を全探索
                    for(int nx = 1; nx < 5; nx++){
                        // AGC, GAC, ACG, A?GC, AG?C がダメ
                        if(k == 1 && j == 3 && nx == 2) continue;
                        if(k == 3 && j == 1 && nx == 2) continue;
                        if(k == 1 && j == 2 && nx == 3) continue;
                        if(l == 1 && j == 3 && nx == 2) continue;
                        if(l == 1 && k == 3 && nx == 2) continue;
                        dp[i + 1][nx][j][k] += dp[i][j][k][l];
                    }
                }
            }
        }
    }

    mint ans = 0;
    for(int j = 0; j < 5; j++){
        for(int k = 0; k < 5; k++){
            for(int l = 0; l < 5; l++){
                ans += dp[N][j][k][l];
            }
        }
    }

    cout << ans << endl;
}