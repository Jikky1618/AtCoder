#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    auto prime = prime_factorize(N);
    ll ans = 0;
    for(auto pf: prime){
        ll val = 1, exp = pf.second;
        // 各素因数pについて、Nがp^1, p^2,...で割れるか判定
        while(val <= exp){
            ans++;
            exp -= val;
            val++;
        }
    }

    cout << ans << endl;
}