#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a, b, c;
    cin >> a >> b >> c;
    cout << (b - a == c - b ? "YES" : "NO") << endl;
    return 0;
}