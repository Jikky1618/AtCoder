#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    ll ans = (n) * (n - 1) / 2;

    cout << ans << endl;
    return 0;
}