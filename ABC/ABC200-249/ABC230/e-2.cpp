#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 商列挙: {q, l, r}
// 1 <= i <= nに対し、floor(n / i) = q となるiの範囲が[l, r)となる配列を返す
vector<tuple<ll, ll, ll>> quotient_ranges(ll n){
    vector<tuple<ll, ll, ll>> res;
    for(ll i = 1; i * i <= n; i++){
        res.push_back({n / i, i, i + 1});
    }
    for(int i = n / (ll)(sqrt(n) + 1); i >= 1; i--){
        res.push_back({i, n / (i + 1) + 1, n / i + 1});
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    auto Q = quotient_ranges(N);

    ll ans = 0;
    for(auto [val, l, r]: Q){
        ans += val * (r - l);
    }

    cout << ans << endl;
}