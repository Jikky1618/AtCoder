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

template <class Abel>
struct BinaryIndexedTree {
    int n;
    vector<Abel> dat;
    Abel UNITY_SUM = 0;

    BinaryIndexedTree(int size, Abel unity = 0)
        : n(size), dat(size, unity), UNITY_SUM(unity) {}

    BinaryIndexedTree(const vector<Abel>& vec, Abel unity = 0)
        : n(vec.size()), dat(n, unity) {
        for (int i = 0; i < n; i++) add(i, vec[i]);
    }

    // val[a] += x
    void add(int a, Abel x) {
        for (int i = a; i < n; i |= i + 1) {
            dat[i] += x;
        }
    }

    // 区間 [0, a) の取得
    Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1) {
            res += dat[i];
        }
        return res;
    }

    // 区間 [a, b) の取得
    Abel sum(int a, int b) { return sum(b) - sum(a); }

    Abel all() { return dat.front(); }
};

const int M = 2e5 + 1;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll val = 0;
    // bit1 := A[k] のある箇所に +1
    // bit2 := A[k] のある箇所に +A[k]
    BinaryIndexedTree<ll> bit1(M), bit2(M);
    for(ll k = 0; k < N; k++){
        ll v1 = bit1.sum(0, A[k] + 1);
        ll v2 = bit2.sum(A[k] + 1, M);
        val += (v1 * A[k] + v2) * 2 + A[k];
        debug(v1, v2, val);
        cout << mint(val) * mint((k + 1) * (k + 1)).inv() << '\n';
        bit1.add(A[k], 1);
        bit2.add(A[k], A[k]);
    }
}