#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1LL << 60;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    vector<ll> t(5);
    cin >> n;
    for(int i = 0; i < 5; i++) cin >> t[i];

    ll Min = INF;
    for(int i = 0; i < 5; i++) Min = min(Min, t[i]);

    ll ans = (n + Min - 1) / Min + 4;
    cout << ans << endl;
    return 0;
}