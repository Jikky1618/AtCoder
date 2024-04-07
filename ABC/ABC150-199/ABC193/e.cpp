#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// ax + by = gcd(a, b) を満たす x, y を求める
pair<ll, ll> extgcd(ll a, ll b) {
    if(b == 0) return {1, 0};
    auto [y, x] = extgcd(b, a % b);
    y -= a / b * x;
    return {x, y};
}

// x ≡ r[i] (mod m[i]) を解き, x ≡ r0 (mod. m0) となる (r0, m0) を返す
// m0 := lcm(m[0], m[1], ...)
pair<ll, ll> crt(const vector<ll>& r, const vector<ll>& m) {
    assert(r.size() == m.size());
    int n = r.size();
    ll r0 = 0, m0 = 1;
    for(int i = 0; i < n; i++){
        assert(1 <= m[i]);
        ll r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i], g = gcd(m0, m1);
        // p * m0 + q * m1 = g となる (p, q) を求める
        // このとき p は p * m0 / g ≡ 1 (mod. m1 / g) を満たす
        auto [p, q] = extgcd(m0, m1);
        // r1 ≡ r0 (mod. g) でない場合は解なし
        if((r1 - r0) % g != 0) return {-1, 0};
        // s = (r1 - r0) / g として両辺に s を掛けて
        // p * m0 * s + q * m1 * s = r1 - r0 とする
        // x = r0 + m0 * p * s (= r1 - m1 * p * s) とすると
        // x ≡ r1 (mod. m1), x ≡ r0 (mod. m0) を満たす
        ll u1 = m1 / g;
        ll x = (r1 - r0) / g % u1 * p % u1;
        r0 += m0 * x;
        m0 *= u1; // lcm(m0, m1) = m0 * m1 / g
    }
    r0 = (r0 % m0 + m0) % m0;
    return {r0, m0};
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while(T--){
        ll X, Y, P, Q;
        cin >> X >> Y >> P >> Q;
        ll ans = INF;
        for(int y = 0; y < Y; y++){
            for(int q = 0; q < Q; q++){
                // (2X + 2Y)n + X + y (0 <= y < Y) -> x ≡ X + y (mod 2X + 2Y)
                // (P + Q)m + P + q (0 <= q < Q) -> x ≡ P + q (mod P + Q)
                // となる x を crt で求める
                auto [x, m] = crt({X + y, P + q}, {2 * X + 2 * Y, P + Q});
                if(x != -1) ans = min(ans, x);
            }
        }
        if(ans == INF){
            cout << "infinity" << endl;
        }else{
            cout << ans << endl;
        }
    }
}