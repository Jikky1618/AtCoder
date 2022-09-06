#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a,b,k;
    cin >> a >> b >> k;

    ll ans = 0;
    while(a < b){
        a *= k;
        ans++;
    }

    cout << ans << endl;

    return 0;
}