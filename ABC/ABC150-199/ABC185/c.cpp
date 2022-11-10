#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll l;
    cin >> l;
    
    ll ans = 1;
    for(ll k = 1; k <= 11; k++){
        ans *= l - k;
        ans /= k;
    }

    cout << ans << endl;
    return 0;
}