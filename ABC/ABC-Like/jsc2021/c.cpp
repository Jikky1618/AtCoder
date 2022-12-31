#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B;
    cin >> A >> B;
    
    for(int GCD = B; GCD >= 0; GCD--){
        if(B / GCD - (A - 1) / GCD >= 2){
            cout << GCD << endl;
            break;
        }
    }

    return 0;
}