#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, K;
    cin >> N >> K;

    ll ans = min(N % K, abs((N % K) - K));
    cout << ans << endl;
    return 0;
}