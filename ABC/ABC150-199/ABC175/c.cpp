#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll X, K, D;
    cin >> X >> K >> D;

    X = abs(X); // 0 <= X に

    ll ans = 0;
    if(X / D > K){
        ans = X - K * D;
    }
    if(X / D <= K){
        if((K - X / D) % 2 == 0) ans = X % D;
        if((K - X / D) % 2 == 1) ans = abs(X % D - D);
    }
    
    cout << ans << endl;
    return 0;
}