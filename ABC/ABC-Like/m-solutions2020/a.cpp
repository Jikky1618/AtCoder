#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int X;
    cin >> X;
    
    X -= 400;
    int ans = 8;
    while(X >= 0){
        X -= 200;
        ans--;
    }

    cout << ans << endl;
    return 0;
}