#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s,t,u;
    int a,b;
    cin >> s >> t >> a >> b >> u;

    if(u == s) a--;
    if(u == t) b--;

    cout << a << " " << b << endl;
    
    return 0;
}