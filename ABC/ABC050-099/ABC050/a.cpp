#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B;
    char op;
    cin >> A >> op >> B;
    cout << (op == '+' ? A + B : A - B) << endl;
    return 0;
}