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

template<class Abel>
struct BinaryIndexedTree {
    int n;
    vector<Abel> dat;
    Abel UNITY_SUM = 0;

    BinaryIndexedTree(int size, Abel unity = 0)
        : n(size), dat(size + 1, unity), UNITY_SUM(unity) {}

    // val[a] += x
    // a is 1-indexed
    void add(int a, Abel x){
        for(int i = a; i <= n; i += i & -i){
            dat[i] += x;
        }
    }

    // val[1] + ... + val[a]
    // a is 1-indexed
    Abel sum(int a){
        Abel res = UNITY_SUM;
        for(int i = a; i > 0; i -= i & -i){
            res += dat[i];
        }
        return res;
    }

    // val[a] + ... + val[b]
    // a, b is 1-indexed
    Abel sum(int a, int b){
        return sum(b) - sum(a - 1);
    }

    Abel all(){
        return dat.front();
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    BinaryIndexedTree<mint> bit1(N), bit2(N), bit3(N);
    for(int i = 1; i <= N; i++){
        bit1.add(i, A[i - 1]);
        bit2.add(i, (mint)i * A[i - 1]);
        bit3.add(i, (mint)i * i * A[i - 1]);
    }

    while(Q--){
        int type; cin >> type;
        if(type == 1){
            int x, v; cin >> x >> v;
            bit1.add(x, -(mint)A[x - 1]);
            bit2.add(x, -(mint)x * A[x - 1]);
            bit3.add(x, -(mint)x * x * A[x - 1]);
            A[x - 1] = v;
            bit1.add(x, (mint)A[x - 1]);
            bit2.add(x, (mint)x * A[x - 1]);
            bit3.add(x, (mint)x * x * A[x - 1]);
        }
        if(type == 2){
            int x; cin >> x;
            mint f1 = bit1.sum(x) * x * (x + 1);
            mint f2 = bit2.sum(x) * (2 * x + 1);
            mint f3 = bit3.sum(x);
            mint ans = (f1 - f2 + f3) / 2;
            cout << ans << '\n';
        }
    }
}