#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B, C;
    cin >> A >> B >> C;

    ll G = gcd(gcd(A, B), C);
    ll Ans = A / G + B / G + C / G - 3;

    cout << Ans << endl;
    return 0;
}