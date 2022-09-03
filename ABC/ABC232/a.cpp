#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;

    int ans;
    ans = (s[0] - '0') * (s[2] - '0');
    cout << ans << endl;
    
    return 0;
}