#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int v,t,s,d;
    cin >> v >> t >> s >> d;

    if(v * t <= d && d <= v * s) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}