#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    
    bool a = false,b = false;
    for(int i = 0; i < 3; i++){
        if(s[i] == 'A') a = true;
        if(s[i] == 'B') b = true;
    }

    if(a & b) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}