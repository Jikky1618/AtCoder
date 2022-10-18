#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2 >> d2;

    if(m1 != m2 && d2 - 1 != d1){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}