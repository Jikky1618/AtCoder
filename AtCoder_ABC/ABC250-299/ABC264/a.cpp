#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int l,r;
    cin >> l >> r;
    string str = "atcoder";

    cout << str.substr(l-1,r-l+1) << endl;
    
    return 0;
}