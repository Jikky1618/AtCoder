#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    if(pow(-2,31) <= n && n < pow(2,31)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}