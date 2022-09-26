#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,a,b;
    cin >> n >> a >> b;

    ll ans = 0;
    ans += n / (a + b) * a;
    ans += min(a,n % (a + b));

    cout << ans << endl;
    
    return 0;
}