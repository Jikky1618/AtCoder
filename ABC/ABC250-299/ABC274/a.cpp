#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(3);
    double a,b;
    cin >> a >> b;
    cout << round(b / a * 1000) / 1000 << endl;
    return 0;
}