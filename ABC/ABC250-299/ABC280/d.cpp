#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>> prime_factorize(ll x){
    vector<pair<ll, ll>> factor;
    for (ll a = 2; a * a <= x; a++){
        if (x % a != 0) continue;
        ll exp = 0;
        while (x % a == 0) {
            exp++, x /= a;
        }
        factor.push_back({a, exp});
    }
		if (x != 1) factor.push_back({x, 1});
		return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll k;
    cin >> k;

    // x は p で何回割れるか。
    auto how_many = [&](ll x, ll p){
        ll res = 0;
        while(x % p == 0) x /= p, res++;
        return res;
    };

    ll ans = 0;
    auto pf = prime_factorize(k);
    for(auto &&[p,e]: pf){
        ll n = 0, cnt = 0;
        while(e > cnt){
            n += p;
            cnt += how_many(n, p);
        }
        ans = max(ans, n);
    }

    cout << ans << endl;
}