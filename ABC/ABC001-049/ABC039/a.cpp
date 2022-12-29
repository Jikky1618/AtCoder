#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, C;
    cin >> A >> B >> C;
    cout << 2 * (A * B + B * C + C * A) << endl;
    return 0;
}