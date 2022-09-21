#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int l,r;
    string S;
    cin >> l >> r >> S;

    string revS = S.substr(l-1,r-l+1);
    reverse(revS.begin(), revS.end());
    S = S.substr(0,l-1) + revS + S.substr(r);

    cout << S << endl;

    return 0;
}