#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, D;
    cin >> A >> D;
    cout << max((A + 1) * D, A * (D + 1)) << endl;
    return 0;
}