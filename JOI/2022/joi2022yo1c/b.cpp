#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int S, A, B;
    cin >> S >> A >> B;
    cout << max(0, (S - A + B - 1)) / B * 100 + 250 << endl;
    return 0;
}