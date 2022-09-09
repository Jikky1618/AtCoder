#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int main(){
    ll n;
    cin >> n;

    ll ans = n % MOD;
    if(ans < 0) ans += MOD;

    cout << ans << endl;

    return 0;
}
