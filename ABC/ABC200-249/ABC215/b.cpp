#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;
    
    ll k = 0, val = 1;
    while(val * 2 <= N){
        val *= 2;
        k++;
    }

    cout << k << endl;
}