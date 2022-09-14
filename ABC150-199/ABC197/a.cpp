#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    s += s[0]; s.erase(s.begin());

    cout << s << endl;
    
    return 0;
}