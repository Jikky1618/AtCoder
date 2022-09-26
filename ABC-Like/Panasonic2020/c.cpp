#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,c;
    cin >> a >> b >> c;

    bool judge = (4 * a * b < (c - a - b) * (c - a - b) && 0 < c - a - b);
    if(judge) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}