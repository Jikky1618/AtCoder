#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    
    ll ans = n / 3 + n / 5 - n / 15;
    cout << ans << endl;
    return 0;
}