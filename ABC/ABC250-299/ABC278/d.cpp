#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,q;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> q;

    ll base = 0;
    map<int, ll> mp;
    for(int i = 0; i < n; i++) mp[i] = a[i];

    for(int _ = 0; _ < q; _++){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x; base = x;
            mp.clear();
        }
        if(type == 2){
            int i, x; cin >> i >> x;
            mp[i-1] += x;
        }
        if(type == 3){
            int i; cin >> i;
            cout << mp[i-1] + base << endl;
        }
    }
    return 0;
}