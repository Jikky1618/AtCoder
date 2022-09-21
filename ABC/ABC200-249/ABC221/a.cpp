#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,res;
    cin >> a >> b;
    
    res = pow(32,(a-b));
    
    cout << res << endl;

    return 0;
}