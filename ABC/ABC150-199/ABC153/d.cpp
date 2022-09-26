#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h;
    cin >> h;

    ll cnt = 1,ans = 0;
    while(0 < h){
        ans += cnt;
        h /= 2;
        cnt *= 2;
    }

    cout << ans << endl;
    
    return 0;
}