#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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

int F(ll a, ll b){
    return max(to_string(a).size(), to_string(b).size());
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    vector<ll> ab = make_is_divisors(n);
    int ans = INF;
    for(auto a: ab){
        for(auto b: ab){
            if(a * b == n) ans = min(ans, F(a, b));
        }
    }

    cout << ans << endl;
    return 0;
}