#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    if(a <= b) cout << a << endl;
    else cout << a - 1 << endl;
    return 0;
}