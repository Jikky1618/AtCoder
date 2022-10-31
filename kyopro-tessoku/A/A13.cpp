#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // しゃくとり法
    vector<int> r(n);
    for(int i = 0; i < n; i++){
        if(i == 0) r[i] = 0;
        else r[i] = r[i-1];
        // ギリギリまで増やす
        while(r[i] < n-1 && a[r[i]+1]-a[i] <= k){
            r[i]++;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += r[i] - i;

    cout << ans << endl;
    return 0;
}