#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    ll blue = a,red = 0;

    for(int i = 1; i <= a; i++){
        blue += b;
        red += c;
        if(blue <= red * d){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}