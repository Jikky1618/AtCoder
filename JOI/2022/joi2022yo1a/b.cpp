#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int X, Y, Z;
    cin >> X >> Y >> Z;
    cout << (X + Y <= Z ? 1 : 0) << endl;
    return 0;
}