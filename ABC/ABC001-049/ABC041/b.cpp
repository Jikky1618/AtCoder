#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B, C;
    cin >> A >> B >> C;

    ll ans = A * B % MOD * C % MOD;
    cout << ans << endl;
    return 0;
}