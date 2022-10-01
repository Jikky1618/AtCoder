#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a;
    string s;
    cin >> a >> s;
    
    if(a >= 3200) cout << s << endl;
    else cout << "red" << endl;
    return 0;
}