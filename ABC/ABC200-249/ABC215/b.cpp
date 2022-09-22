#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    ll k = 0,val = 1;
    while(val <= n){
        val *= 2;
        k++;
    }

    cout << k - 1 << endl;
    
    return 0;
}