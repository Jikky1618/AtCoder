#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    if(a % b == 0) cout << 0 << endl;
    else cout << b - a % b << endl;
    return 0;
}