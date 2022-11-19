#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,Q;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> Q;

    for(int _ = 0; _ < Q; _++){
        int q; cin >> q;
        if(q == 1){
            int x; cin >> x;
            vector<ll> b(n,x);
            a = b;
        }
        if(q == 2){
            int i, x; cin >> i >> x;
            a[i-1] += x;
        }
        if(q == 3){
            int i; cin >> i;
            cout << a[i-1] << endl;
        }
    }
    return 0;
}