#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << (min(B, D) - max(A, C) >= 0 ? "Yes" : "No") << endl;
    return 0;
}