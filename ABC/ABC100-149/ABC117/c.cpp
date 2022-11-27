#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++) cin >> x[i];

    sort(x.begin(), x.end());
    // 隣接する座標の差
    vector<int> d(m - 1);
    for(int i = 0; i < m - 1; i++) d[i] = x[i + 1] - x[i];
    sort(d.begin(), d.end());

    ll ans = 0;
    // コマはm-n個の座標に訪れる
    int cnt = max(0, m - n);
    for(int i = 0; i < cnt; i++) ans += d[i];

    cout << ans << endl;
    return 0;
}