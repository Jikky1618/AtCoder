#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;

    if(x % 100 == 0) cout << 100 << endl;
    else cout << (100 - x % 100) << endl;
    
    return 0;
}