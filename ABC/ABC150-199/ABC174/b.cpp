#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,d;
    cin >> n >> d;
    vector<ll> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        ll dist = x[i] * x[i] + y[i] * y[i];
        if(dist <= (ll)d * d) ans++;
    }

    cout << ans << endl;

    return 0;
}