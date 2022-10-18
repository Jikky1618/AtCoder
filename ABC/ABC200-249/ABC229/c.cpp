#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,w;
    cin >> n >> w;
    vector<pair<ll, ll>> c(n);
    for(int i = 0; i < n; i++) cin >> c[i].first >> c[i].second;

    sort(c.begin(),c.end(), greater<pair<ll, ll>>());
    ll ans = 0, g = 0;
    for(int i = 0; i < n; i++){
        ans += c[i].first * min(c[i].second, w);
        w -= min(w, c[i].second);
    }

    cout << ans << endl;
    return 0;
}