#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    
    ll ans = 0;
    /* 
    if(n >= pow(10,3)) ans += n - pow(10,3) + 1;
    if(n >= pow(10,6)) ans += n - pow(10,6) + 1;
    if(n >= pow(10,9)) ans += n - pow(10,9) + 1;
    if(n >= pow(10,12)) ans += n - pow(10,12) + 1;
    if(n >= pow(10,15)) ans += n - pow(10,15) + 1;
    */
    for(int i = 3; i <= 15; i += 3){
        if(n >= pow(10,i)) ans += n - pow(10,i) + 1;
    }
    cout << ans << endl;

    return 0;
}