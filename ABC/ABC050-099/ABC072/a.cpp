#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int X, t;
    cin >> X >> t;
    cout << max(X - t, 0) << endl;
    return 0;
}