#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll N,X;
    cin >> N >> X;
    vector<ll> x(N);
    for(int i = 0; i < N; i++) cin >> x[i];

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans = __gcd(ans, abs(X - x[i]));
    }

    cout << ans << endl;
    return 0;
}