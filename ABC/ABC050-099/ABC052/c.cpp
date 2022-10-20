#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

vector<pair<ll,ll>> prime_factorize(ll x){
    vector<pair<ll, ll>> factor;
    for (ll a = 2; a * a <= x; a++){
        if (x % a != 0) continue;
        ll exp = 0; // 指数

        // 割れる限り割り続ける
        while (x % a == 0) {
            exp++;
            x /= a;
        }

        // その結果を push
        factor.push_back({a, exp});
    }
    if (x != 1) factor.push_back({x, 1});
    return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<ll> exp(n + 1); // exp[p] := p の指数
    for(int i = 2; i <= n; i++){
        auto m = prime_factorize(i); // iの素因数分解
        for(auto &&p :m) exp[p.first] += p.second;
    }

    ll ans = 1;
    for(int p = 2; p <= n; p++){
        ans = ans * (exp[p] + 1) % MOD;
    }

    cout << ans << endl;
    return 0;
}