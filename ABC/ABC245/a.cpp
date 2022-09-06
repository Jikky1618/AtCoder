#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    if(a < c) cout << "Takahashi" << endl;
    if(a > c) cout << "Aoki" << endl;
    if(a == c){
        if(b < d) cout << "Takahashi" << endl;
        if(b > d) cout << "Aoki" << endl;
        if(b == d) cout << "Takahashi" << endl;
    }

    return 0;
}