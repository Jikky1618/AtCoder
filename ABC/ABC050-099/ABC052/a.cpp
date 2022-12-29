#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << max(A * B, C * D) << endl;
    return 0;
}