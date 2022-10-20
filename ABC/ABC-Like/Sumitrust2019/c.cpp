#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;

    int ans = 0;
    for(int i = 0; i < x; i++){
        if(i * 100 <= x && x <= i * 105) ans = 1;
    }
    
    cout << ans << endl;
    return 0;
}