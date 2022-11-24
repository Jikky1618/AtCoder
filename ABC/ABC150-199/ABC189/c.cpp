#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int l = 0; l < n; l++){
        int x = a[l];
        for(int r = l; r < n; r++){
            x = min(x, a[r]);
            ans = max(ans, x * (r - l + 1));
        }
    }

    cout << ans << endl;
    return 0;
}