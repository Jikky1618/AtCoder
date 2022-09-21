#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s,t;
    cin >> s >> t;

    bool judge = true;
    if(s.size() > t.size()) judge = false;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i])  judge = false;
    }
    
    if(judge) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}