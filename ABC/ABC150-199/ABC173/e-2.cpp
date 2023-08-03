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
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 正の数, 負の数をカウント
    int cntp = 0, cntn = 0;
    vector<ll> X, Y;
    for(int i = 0; i < N; i++){
        if(A[i] >= 0){
            cntp++;
            X.emplace_back(A[i]);
        }else{
            cntn++;
            Y.emplace_back(A[i]);
        }
    }

    mint ans = 1;
    // 積が必ず負になるケース
    if((cntn == N && K % 2 == 1) || (N == K && cntn % 2 == 1)){
        stable_sort(A.begin(), A.end(), [](const auto& left, const auto& right){
            return abs(left) < abs(right);
        });
        // 絶対値が小さい(値が大きい)順に K 個選ぶ
        for(int i = 0; i < K; i++) ans *= A[i];
    }else{
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        // K が奇数なら, 正の整数で最も大きい 1 つを選ぶ
        if(K % 2 == 1){
            ans *= X.back();
            X.pop_back();
            K--, cntp--;
        }
        // K が偶数なら, 2 個セットをそれぞれ作る
        vector<ll> S;
        reverse(X.begin(), X.end());
        for(int i = 0; i + 1 < cntp; i += 2){
            S.emplace_back(X[i] * X[i + 1]);
        }
        for(int i = 0; i + 1 < cntn; i += 2){
            S.emplace_back(Y[i] * Y[i + 1]);
        }
        sort(S.begin(), S.end(), greater<ll>());

        for(int i = 0; i < K / 2; i++) ans *= S[i];
    }

    cout << ans << endl;
}