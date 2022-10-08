#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(a % b == 0){
        return b;
    }else{
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a,b) * b;
}

ll num(ll n, ll c, ll d){
    ll res = n - n / c - n / d + n / lcm(c, d);
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    ll ans = num(b, c, d) - num(a - 1, c, d);

    cout << ans << endl;
    return 0;
}