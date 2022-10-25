#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1LL << 60;

ll price(ll &a, ll &b, ll &n){
    ll sum = a * n + b * to_string(n).size();
    return sum;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,x;
    cin >> a >> b >> x;

    ll ok = 0;
    ll ng = pow(10, 9) + 1;
    while (abs(ok - ng) > 1) {
        ll mid = ng + (ok - ng) / 2;
        if (price(a, b, mid) <= x) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}