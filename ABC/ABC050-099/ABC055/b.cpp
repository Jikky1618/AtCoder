#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    ll ans = 1;
    for(int i = 1; i <= n; i++){
        ans = (ans * i) % MOD;
    }

    cout << ans << endl;
    return 0;
}