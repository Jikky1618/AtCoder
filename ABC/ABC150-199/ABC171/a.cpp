#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    
    if('a' <= s[0] && s[0] <= 'z') cout << 'a' << endl;
    if('A' <= s[0] && s[0] <= 'Z') cout << 'A' << endl;

    return 0;
}