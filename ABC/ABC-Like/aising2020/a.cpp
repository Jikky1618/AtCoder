#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int L, R, d;
    cin >> L >> R >> d;
    cout << R / d - (L - 1) / d << endl;
    return 0;
}