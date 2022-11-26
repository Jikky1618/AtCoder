#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double; 

ll a,b;
ld f(ll x){
    return (a / sqrt(1 + x)) + b * x;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> a >> b;

    ll l = 0, r = a / b;
    while(r - l > 2){
        ll p1 = (l * 2 + r) / 3;
        ll p2 = (l + r * 2) / 3;
        if(f(p1) < f(p2)){
            r = p2;
        }else{
            l = p1;
        }
    }
    ld ans = a;
    for (ll i = l; i <= r; i++){
        ans = min(ans, f(i));
    }

    cout << ans << endl;
    return 0;
}