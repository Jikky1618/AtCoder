#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a, b;
    cin >> a >> b;
    cout << min(abs(a - b), 10 - max(a, b) + min(a, b)) << endl;
    return 0;
}