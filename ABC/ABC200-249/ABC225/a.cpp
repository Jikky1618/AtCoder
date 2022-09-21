#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string str;
    cin >> str;

    if(str[0] == str[1] && str[1] == str[2]) cout << 1 << endl;
    else if(str[0] != str[1] && str[1] != str[2] && str[0] != str[2]) cout << 6 << endl;
    else cout << 3 << endl;

    return 0;
}