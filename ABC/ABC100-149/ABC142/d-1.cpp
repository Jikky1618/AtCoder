#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<pair<ll, ll>> prime_factorize(ll n){
    vector<pair<ll, ll>> factor;
    for (ll p = 2; p * p <= n; p++){
        if (n % p != 0) continue;
        ll exp = 0;
        while (n % p == 0){
            exp++;
            n /= p;
        }
        factor.emplace_back(p, exp);
    }
	if (n != 1) factor.emplace_back(n, 1);
	return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B;
    cin >> A >> B;

    // それぞれの素因数を求めて, 全探索
    auto pfA = prime_factorize(A);
    auto pfB = prime_factorize(B);

    // 公約数の素数を探す
    map<ll, int> mp;
    for(auto [p, e]: pfA) mp[p]++;
    for(auto [p, e]: pfB) mp[p]++;
    
    int cnt = 0;
    for(auto [key, val]: mp){
        if(val == 2) cnt++;
    }

    // 公約数の素数 と 1 が今回の条件を満たす
    // よって cnt + 1 が答え
    cout << cnt + 1 << endl;
}