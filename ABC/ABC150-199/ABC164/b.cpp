#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    while(1){
        c -= b; // Takahashi's attack
        if(c <= 0){
            cout << "Yes" << endl;
            break;
        }
        a -= d; // Aoki's attack
        if(a <= 0){
            cout << "No" << endl;
            break;
        }
    }
    
    return 0;
}