#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a, b;
    cin >> a >> b;
    if(a + b == 15) cout << '+' << endl;
    else if(a * b == 15) cout << '*' << endl;
    else cout << 'x' << endl;
    return 0;
}