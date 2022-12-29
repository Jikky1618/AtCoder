#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int h, m;
    cin >> h >> m;

    h %= 12;
    double diff = abs(6 * m - (h * 60 + m) / 2);
    cout << min(diff, 360 - diff) << endl;
    return 0;
}