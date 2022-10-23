#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1LL << 60;

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
    ll n;
    cin >> n;
    
    auto div = make_is_divisors(n);
    ll ans = LINF;
    for(auto &&i: div){
        for(auto &&j: div){
            if(i * j == n) ans = min(ans, i - 1 + j - 1);
        }
    }

    cout << ans << endl;
    return 0;
}