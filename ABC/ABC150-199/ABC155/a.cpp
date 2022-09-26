#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a == b && b == c && a == c) cout << "No" << endl;
    else if(a != b && b != c && a != c) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}