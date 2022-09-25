#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = pow(10,18);
 
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // find 0
    if(find(a.begin(), a.end(),0) != a.end()){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int  i = 0; i < n; i++){
        // find overflow
        if(INF / ans < a[i]){
            cout << -1 << endl;
            return 0;
        }
        ans *= a[i];
    }

    cout << ans << endl;
    
    return 0;
}