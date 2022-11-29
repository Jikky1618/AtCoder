#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string n;
    cin >> n;

    for(auto&& c: n){
        if(c == '9') c = '1';
        else if(c == '1') c = '9';
    }

    cout << n << endl;
    return 0;
}