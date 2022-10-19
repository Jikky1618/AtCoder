#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> makeIsDivisors(ll x){
    vector<ll> divisors;
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            divisors.push_back(i);
            // 重複しないならば i の相方である N/i も push
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

    vector<ll> ans = makeIsDivisors(n);

    for(auto i: ans) cout << i << endl;
    return 0;
}