#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k,x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int i = 0; i < n; i++) ans += a[i];

    // a[i] > x の商品を出来るだけ割引
    ll used = 0;
    for(int i = 0; i < n; i++) used += (a[i] / x);
    used = min(used, k);
    ans -= used * x;
    k -= used;

    // a[i] < x の内、金額が高い商品を出来るだけ0円に
    for(int i = 0; i < n; i++) a[i] %= x;
    sort(a.begin(), a.end(),greater<int>());
    for(int i = 0; i < n; i++){
        if(0 < k){
            k--;
            ans -= a[i];
        }else{
            break;
        }
    }

    cout << ans << endl;
    return 0;
}