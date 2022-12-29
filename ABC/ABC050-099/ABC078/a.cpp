#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    char X, Y;
    cin >> X >> Y;
    if(X < Y) cout << "<" << endl;
    else if(X > Y) cout << ">" << endl;
    else cout << "=" << endl;
    return 0;
}