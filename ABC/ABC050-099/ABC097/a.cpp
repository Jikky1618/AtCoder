#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}