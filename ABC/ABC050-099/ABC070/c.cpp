#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll my_gcd(ll a, ll b){
    if(a % b == 0){
        return b;
    }else{
        return my_gcd(b, a % b);
    }
}
 
ll my_lcm(ll a, ll b){
    return a / my_gcd(a,b) * b;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];

    ll ans = 1;
    for(int i  = 0; i < n; i++){
        ans = my_lcm(ans, t[i]);
    }

    cout << ans << endl;
    return 0;
}