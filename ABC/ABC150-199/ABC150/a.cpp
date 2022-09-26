#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k,x;
    cin >> k >> x;

    if(x <= 500 * k) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}