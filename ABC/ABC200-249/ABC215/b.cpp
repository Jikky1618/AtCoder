#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    ll k = 0,value = 1;
    while(1){
        if(value > n){
            break;
        }
        k++;
        value *= 2;
    }
    cout << k - 1 << endl;

    return 0;
}