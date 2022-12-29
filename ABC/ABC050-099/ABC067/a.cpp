#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B;
    cin >> A >> B;
    cout << (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0 ? "Possible" : "Impossible") << endl;
    return 0;
}