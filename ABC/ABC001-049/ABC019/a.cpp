#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c - min({a, b, c}) - max({a, b, c}) << endl;
    return 0;
}