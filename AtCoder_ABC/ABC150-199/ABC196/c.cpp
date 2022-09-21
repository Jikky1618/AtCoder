#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    for(ll i = 0; ; i++){
        if(stoll(to_string(i) + to_string(i)) > n){
            cout << i - 1 << endl;
            return 0;
        }
    }
    return 0;
}