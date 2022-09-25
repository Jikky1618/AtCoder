#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n % 1000 == 0) cout << 0 << endl;
    else cout << 1000 - (n % 1000) << endl;
    return 0;
}