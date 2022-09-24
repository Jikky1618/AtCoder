#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    if(s.back() == 's') s = s + "es";
    else s = s + 's';

    cout << s << endl;
    
    return 0;
}