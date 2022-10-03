#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    int k = (a + b) / 2;
    if(abs(a - k) == abs(b - k)){
        cout << k << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}