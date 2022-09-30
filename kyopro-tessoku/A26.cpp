#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(ll x){
    for(ll i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    vector<int> x(q);
    for(int i = 0; i < q; i++) cin >> x[i];

    for(int i = 0; i < q; i++){
        if(isPrime(x[i])){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}