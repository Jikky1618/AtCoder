#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x1,x2,x3,x4,x5;
    cin >> x1 >> x2 >> x3 >> x4 >> x5;
    int sum = x1 + x2 + x3 + x4 + x5;

    cout << 15 - sum << endl;

    return 0;
}