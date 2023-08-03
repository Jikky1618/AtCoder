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
        // 負の値を小さい順に, 正の値を大きい順にする
        sort(X.begin(), X.end(), greater<ll>());
        sort(Y.begin(), Y.end());
        vector<ll> Z; // ここに K 個を格納する

        unsigned px = 0, py = 0; // px := X の何番目, py := の何番目
        // K 個選ぶまで繰り返す
        while(int(Z.size()) < K){
            // 負の整数を選ぶ場合
            // 1. K 個のうち, 2 個以上選んでいない
            // 2. 選んでいない負の整数が 2 個以上
            // 3. 選んでいない正の整数が 1 個以下 or 負の積の方が正の積より大きい
            if(int(Z.size()) + 1 < K && py + 1 < Y.size() && (px + 1 >= X.size() || X[px] * X[px + 1] <= Y[py] * Y[py + 1])){
                // 2 個追加
                Z.emplace_back(Y[py]);
                Z.emplace_back(Y[py + 1]);
                py += 2;
            // 正の整数を選ぶ場合
            // K 個のうち, あと 1 個選んでいない or 選んでいない負の整数が 1 個以下 or 正の積の方が負の積より大きい
            }else{
                // 1 個追加
                Z.emplace_back(X[px]);
                px++;
            }
        }
        debug(Z);
        for(int i = 0; i < K; i++) ans *= Z[i];
    }

    cout << ans << endl;
}