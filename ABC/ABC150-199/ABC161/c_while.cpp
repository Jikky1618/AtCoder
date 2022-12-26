#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    
    while(n > n%k) n %= k;
    while(n > abs(n-k)) n = abs(n-k);

    cout << n << endl;
    return 0;
}