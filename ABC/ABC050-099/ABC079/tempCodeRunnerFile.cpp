#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> l(n);
    for(int i = 0; i < n; i++){
        if(i == 0) l[i] = 2;
        else if(i == 1) l[i] = 1;
        else l[i] = l[i - 1] + l[i - 2];
    }

    cout << l[n] << endl;
    return 0;
}