#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s1,s2;
    cin >> s1 >> s2;

    if(s1 == "#." && s2 == ".#") cout << "No" << endl;
    else if(s1 == ".#" && s2 == "#.") cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}