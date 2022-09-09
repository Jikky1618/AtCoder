#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int x,y,n;
    cin >> x >> y >> n;

    int ans = 0;
    if(3 * x < y) ans = x * n;
    else ans = y * (n / 3) + x * (n % 3);

    cout << ans << endl;
    
    return 0;
}