#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    int doSum = 0;
    for(int i = 0; i < m; i++) doSum += a[i];
    int ans = n - doSum;

    if(0 <= ans) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}