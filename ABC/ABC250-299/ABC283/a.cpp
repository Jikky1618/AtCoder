#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A,B;
    cin >> A >> B;
    ll ans = pow(A, B);
    cout << ans << endl;
    return 0;
}