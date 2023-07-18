#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

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
    ll K;
    cin >> K;

    auto pf = prime_factorize(K);
    auto how_many = [](ll N, ll p) -> ll {
        int res = 0;
        while(N % p == 0) N /= p, res++;
        return res;
    };

    ll ans = 0;
    for(auto [p, e]: pf){
        // N := p^e を倍数に持つ最小の N!
        // cnt := p で何回割ったか
        ll N = 0, cnt = 0;
        while(cnt < e){
            N += p; // cnt の更新が来るのは p, 2p, 3p, ...
            cnt += how_many(N, p); // 更新が来たとき,  kp が何回で割れるかを調べる
        }
        ans = max(ans, N);
    }

    cout << ans << endl;
}