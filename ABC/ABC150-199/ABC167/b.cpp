#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    
    ll ans = 0;
    if(k < a) ans = k;
    else if(a <= k && k < a + b) ans = a;
    else if(a + b <= k && k <= a + b + c) ans = a - (k - a - b);

    cout << ans << endl;

    return 0;
}