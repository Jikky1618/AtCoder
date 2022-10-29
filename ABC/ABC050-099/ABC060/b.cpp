#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;

    bool flag = false;
    for(int i = a; i <= a * b; i += a){
        if(i % b == c) flag = true;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}