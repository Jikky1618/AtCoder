#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<pair<ll,ll>> prime_factorize(ll n){
    vector<pair<ll, ll>> factor;
    for (ll p = 2; p * p <= n; p++){
        if (n % p != 0) continue;
        ll exp = 0;
        while (n % p == 0){ // 割れるまで割り続ける
            exp++;
            n /= p;
        }
        // 結果をpush
        factor.push_back({p, exp});
    }
	if (n != 1) factor.push_back({n, 1});
	return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;
    
    auto pf = prime_factorize(N);
    ll k = 0; // 素数のパーツの数
    for(auto[p, exp]: pf){
        k += exp;
    }

    int ans = 0, val = 1;
    while(val < k){
        val *= 2;
        ans++;
    }

    cout << ans << endl;
}