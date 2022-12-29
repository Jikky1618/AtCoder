#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int X, A, B;
    cin >> X >> A >> B;
    cout << (X - A) % B << endl;
    return 0;
}