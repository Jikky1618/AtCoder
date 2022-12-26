#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int x3 = x2 - dy;
    int y3 = y2 + dx;
    int x4 = x1 - dy;
    int y4 = y1 + dx;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}