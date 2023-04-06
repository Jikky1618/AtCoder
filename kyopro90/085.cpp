#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<ll> make_is_divisors(ll x){
    vector<ll> divisors;
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            divisors.push_back(i);
            // 重複しないならば i の相方である x/i も push
            if(x / i != i) divisors.push_back(x / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll K;
    cin >> K;

    auto pf = make_is_divisors(K);
    int n = pf.size();

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if((K / pf[i]) % pf[j] != 0) continue; // ちゃんと割り切れない場合continue
            ll c = (K / pf[i]) / pf[j];
            if(pf[j] <= c && binary_search(pf.begin(), pf.end(), c)) ans++;
        }
    }

    cout << ans << endl;
}