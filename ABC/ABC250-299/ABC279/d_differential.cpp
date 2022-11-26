#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll LINF = 1LL << 60;

ll a,b;
ld f(ll x){
    return a / sqrt(1 + x) + b * x;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> a >> b;

    ll Min = pow((ld)(2 * b) / (ld)a, -2.0 / 3.0) - 1;
    ld ans = LINF;
    for(ll i = max(Min - 5 ,0LL); i <= min(Min + 5, a / b); i++){
        ans = min(ans, f(i));
    }

    cout << ans << endl;
    return 0;
}