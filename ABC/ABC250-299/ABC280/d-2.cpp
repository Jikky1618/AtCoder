#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// n! が持つ素因数 p の個数を数える
// p は素数
ll legendre(ll n, ll p){
    ll res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

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
    // K の素因数とその数を求める
    auto pf = prime_factorize(K);

    // ルジャンドルの定理で K の素因数を K 以上に持っているかを求める
    auto check = [&](ll mid) -> bool {
        for(auto [p, e]: pf){
            if(legendre(mid, p) < e) return false;
        }
        return true;
    };

    // K の素因数を K 以上多く持っている最小の N! を求める
    ll ok = K, ng = 1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    cout << ok << endl;
}