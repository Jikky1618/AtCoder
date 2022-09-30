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
    int x;
    cin >> x;

    for(int i = x;;i++){
        if(isPrime(i)){
            cout << i << endl;
            return 0;
        }
    }


    return 0;
}