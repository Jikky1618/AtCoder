#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> sum(n + 1);
    for(int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];

    vector<ll> num(n - m + 1);
    // num[0]を求める
    for(int i = 0; i < m; i++) num[0] += a[i] * (i + 1);
    // num[i]を求める
    for(int i = 0; i < n - m; i++){
        num[i + 1] = num[i] - (sum[m + i] - sum[i]) + m * a[m + i];
    }

    ll ans = -LINF;
    for(auto &&i: num) if(ans < i) ans = i;
    cout << ans << endl;
    return 0;
}