#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int p,q,r;
    cin >> p >> q >> r;
    cout << min({p + q, p + r,q + r}) << endl;
    return 0;
}