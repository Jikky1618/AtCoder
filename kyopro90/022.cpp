#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long int a,b,c,gcd;
    cin >> a >> b >> c;
    gcd = __gcd(a,__gcd(b,c));
    cout << (a / gcd - 1) + (b / gcd - 1) + (c / gcd - 1) << endl;

    return 0;
}