#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    if((s[0] == 'A' && s[n - 1] == 'B') || s == "BA") cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}