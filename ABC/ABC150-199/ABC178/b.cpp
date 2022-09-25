#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    ll ans = max({max(a,b) * max(c,d),max(a,b) * min(c,d),min(a,b) * max(c,d),min(a,b) * min(c,d)});

    cout << ans << endl;

    return 0;
}