#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll,ll> memo;

ll f(ll n){
    if(n == 0) return 1;
    if(memo.count(n)) return memo[n];
    return memo[n] = f(n/2) + f(n/3);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    ll ans = f(n);
    cout << ans << endl;
    return 0;
}