#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a,b;
    cin >> a >> b;
    
    bool Easy = true;
    while(a + b > 0){
        if((a % 10) + (b % 10) > 9) Easy = false;
        a /= 10;
        b /= 10;
    }

    if(Easy) cout << "Easy" << endl;
    else cout << "Hard" << endl;

    return 0;
}