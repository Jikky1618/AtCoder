#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll x;
    cin >> x;

    if(x >= 0){
        cout << x / 10 << endl;
    }else{
        cout << (x - 10 + 1) / 10 << endl;
    }

    return 0;
}