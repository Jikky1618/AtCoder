#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll x;
    int k;
    cin >> x >> k;

    for(int i = 0; i < k; i++){
        x /= pow(10, i);
        int m = (x % 10);
        if(m < 5) x -= m; // 切り下げ
        else x += (10 - m); // 切り上げ
        x *= pow(10, i);
    }
    cout << x << endl;

    return 0;
}