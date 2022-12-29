#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<string> c(3);
    for(int i = 0; i < 3; i++) cin >> c[i];

    cout << c[0][0] << c[1][1] << c[2][2] << endl;
    return 0;
}