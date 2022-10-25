#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> a(n,vector<ll>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    ll ans = 0;
    vector<ll> p(n);
    for(int t1 = 0; t1 < m; t1++){
        for(int t2 = t1 + 1; t2 < m; t2++){
            ll point = 0;
            for(int i = 0; i < n; i++){
                point += max(a[i][t1], a[i][t2]);
            }
            ans = max(ans, point);
        }
    }

    cout << ans << endl;
    return 0;
}