#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = lower_bound(a.begin(), a.end(),x) - a.begin();
    cout << ans + 1 << endl;
    return 0;
}