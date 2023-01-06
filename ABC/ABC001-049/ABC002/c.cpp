#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ld = long double;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ld xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    ld ans = abs((xa - xc) * (yb - yc) - (xb - xc) * (ya - yc)) / 2;
    cout << ans << endl;
    return 0;
}