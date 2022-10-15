#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    bool flag = true;
    while(l <= r){
        if(s[l] == s[r]) l++, r--;
        else if(s[r] == 'a') r--;
        else {flag = false; break;}
    }
    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}