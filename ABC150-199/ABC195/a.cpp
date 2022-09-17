#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int m,h;
    cin >> m >> h;
    
    if(h % m == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}