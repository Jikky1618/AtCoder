#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, X;
    cin >> A >> B >> X;
    cout << (A <= X && X <= A + B ? "YES" : "NO");
    return 0;
}