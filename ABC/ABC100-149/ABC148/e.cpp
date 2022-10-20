#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    ll ans = 0;
    if(n % 2 == 0){
        ans = n / 10;
        n /= 10;
    
        ll p5 = 5;
        while(p5 <= n){
            ans += n / p5;
            p5 *= 5;
        }
    }

    cout << ans << endl;
    return 0;
}