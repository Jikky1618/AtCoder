#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1);

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    double a,b,h,m;
    cin >> a >> b >> h >> m;

    double theta = (60 * h + m) * 6 - (60 * h + m) * 0.5;
    double ans = a * a + b * b - 2 * a * b * cos(theta * PI / 180);
    cout << sqrt(ans) << endl;

    return 0;
}