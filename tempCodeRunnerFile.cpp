#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n;
    cin >> n;

    ll ans = 0;
    for(ll a = 1; a * a * a <= n; a++){
        for(ll b = 1; a * b * b <= n; b++){
            ans += n / (a * b) - b + 1;
    }

    cout << ans << endl;
    return 0;
}