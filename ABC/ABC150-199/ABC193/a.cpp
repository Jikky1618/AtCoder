#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    double a,b;
    cin >> a >> b;

    double ans = (a - b) / a * 100;

    cout << ans << endl;
    return 0;
}