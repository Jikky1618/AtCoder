#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a <= b && b <= c || c <= b && b <= a) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}