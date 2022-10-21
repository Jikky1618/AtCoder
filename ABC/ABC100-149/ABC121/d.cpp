#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n){ // f(0,n)
    ll mod4 = n % 4;
    if(mod4 == 0) return n;
    if(mod4 == 1) return 1;
    if(mod4 == 2) return n + 1;
    if(mod4 == 3) return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b;
    cin >> a >> b;
    cout << (f(a - 1) ^ f(b)) << endl;
    return 0;
}