#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int x, a, b;
    cin >> x >> a >> b;
    cout << (abs(x - a) < abs(x - b) ? "A" : "B" ) << endl;
    return 0;
}