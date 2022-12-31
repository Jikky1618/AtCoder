#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    char S, T;
    cin >> S >> T;
    cout << (S == 'Y' ? (char)toupper(T) : T) << endl;
    return 0;
}