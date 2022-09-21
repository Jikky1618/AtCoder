#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    double x,y;
    cin >> x >> y;

    if(x >= y){
        cout << 0 << endl;
        return 0;
    }

    cout << ceil((y - x) / 10) << endl;

    return 0;
}