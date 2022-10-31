#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += upper_bound(a.begin(), a.end(),a[i] - k) - a.begin();
    }

    cout << ans << endl;
    return 0;
}