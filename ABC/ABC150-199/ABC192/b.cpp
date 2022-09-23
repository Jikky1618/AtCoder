#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    
    bool unreadable = true;
    for(int i = 0; i < (int)s.length(); i++){
        if(i % 2 == 0 && 'a' <= s[i] && s[i] <= 'z') continue;
        else if(i % 2 == 1 && 'A' <= s[i] && s[i] <= 'Z') continue;
        else unreadable = false;
    }

    if(unreadable) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}