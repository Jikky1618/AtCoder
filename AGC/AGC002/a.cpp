#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll a, b;
    cin >> a >> b;

    if(a <= 0 && 0 <= b){
        cout << "Zero" << endl;
        return 0;
    }

    if(0 < a){
        cout << "Positive" << endl;
        return 0;
    }

    if((abs(a) - abs(b)) % 2){
        cout << "Positive" << endl;
    }else{
        cout << "Negative" << endl;
    }
    return 0;
}