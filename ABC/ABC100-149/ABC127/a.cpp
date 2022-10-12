#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    if(a <= 5){
        cout << 0 << endl; return 0;
    }
    else if(6 <= a && a <= 12){
        cout << b / 2 << endl; return 0;
    }else{
        cout << b << endl; return 0;
    }

    return 0;
}