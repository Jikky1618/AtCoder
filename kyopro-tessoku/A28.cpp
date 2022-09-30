#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 10000;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<char> t(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> t[i] >> a[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(t[i] == '+') ans += a[i];
        if(t[i] == '-') ans -= a[i];
        if(t[i] == '*') ans *= a[i];
        ans = (ans + MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}