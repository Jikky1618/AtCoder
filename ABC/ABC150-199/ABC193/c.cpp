#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    
    set<ll> st;
    for(ll a = 2; a * a <= n; a++){
        ll val = a * a;
        while(val <= n){
            st.insert(val);
            val *= a;
        }
    }

    cout << n - st.size() << endl;
    return 0;
}