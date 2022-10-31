#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int r,g,b;
    cin >> r >> g >> b;
    if((r * 100 + g * 10 + b) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}