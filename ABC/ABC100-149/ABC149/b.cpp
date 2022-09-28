#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,k;
    cin >> a >> b >> k;

    if(k <= a){
        a = a - k;
    }
    else if(a < k && k <= a + b){
        b = b - (k - a); a = 0;
    }
    else{
        a = 0; b = 0;
    }

    cout << a << " " << b << endl;
    return 0;
}