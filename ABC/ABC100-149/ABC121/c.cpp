#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> ab(n);
    for(int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;

    sort(ab.begin(), ab.end());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += ab[i].first * min(ab[i].second, m);
        m -= min(ab[i].second, m);
    }

    cout << ans << endl;
    return 0;
}