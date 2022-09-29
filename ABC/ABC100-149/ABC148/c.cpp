#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b){
    if(a % b == 0){
        return b;
    }else{
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b;
    cin >> a >> b;

    cout << lcm(a,b) << endl;
    return 0;
}