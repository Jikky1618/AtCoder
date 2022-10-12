#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int r,d,x;
    cin >> r >> d >> x; // x is 2000

    for(int i = 0; i < 10; i++){
        x = r * x - d;
        cout << x << endl;
    }
    
    return 0;
}