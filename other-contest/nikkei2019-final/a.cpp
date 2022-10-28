#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> s(n + 1);
    for(int i  = 0; i < n; i++) s[i + 1] = s[i] + a[i];

    for(int k = 1; k <= n; k++){
        ll ans = 0;
        for(int i = 0; i < n - k + 1; i++){
            ans = max(ans, s[i + k] - s[i]);
        }
        cout << ans << endl;
    }
    return 0;
}