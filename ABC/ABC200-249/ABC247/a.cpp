#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;

    s[3] = s[2];
    s[2] = s[1];
    s[1] = s[0];
    s[0] = '0';

    cout << s << endl;

    return 0;
}