#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(ll x){
		if (x < 2) return false;
    for(ll i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    bool flag = false;
    for(int i = a; i <= b; i++){
        bool foundPrime = false;
        for(int j = c; j <= d; j++){
            if(isPrime(i + j)){
                foundPrime = true;
            }
        }
        if(!foundPrime) flag = true;
    }

    if(flag) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}