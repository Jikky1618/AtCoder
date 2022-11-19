#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a,b;
    cin >> a >> b;
    if(a < b) cout << -1 << endl;
    if(a == b) cout << 0 << endl;
    if(a > b) cout << 1 << endl;
    return 0;
}