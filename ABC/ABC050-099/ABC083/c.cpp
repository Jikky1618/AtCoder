#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll x,y;
    cin >> x >> y;
    
    ll ans = 0, cnt = x;
    while(cnt <= y){
        cnt *= 2;
        ans++;
    }
    
    cout << ans << endl;
    return 0;
}