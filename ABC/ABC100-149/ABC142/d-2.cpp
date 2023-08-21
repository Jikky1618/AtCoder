#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 素因数分解{素数, 次数}の配列を返す
vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> factor;
    for (ll p = 2; p * p <= N; p++) {
        if (N % p != 0) continue;
        ll exp = 0;
        while (N % p == 0) {
            exp++;
            N /= p;
        }
        factor.emplace_back(p, exp);
    }
    if (N != 1) factor.emplace_back(N, 1);
    return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B;
    cin >> A >> B;

    // GCD の約数であることは公約数であることと同値
    ll G = gcd(A, B);
    // 公約数の素数 と 1 が今回の条件を満たす
    // よって pf.size() + 1 が答え
    ll ans = prime_factorize(G).size() + 1;
    cout << ans << endl;
}