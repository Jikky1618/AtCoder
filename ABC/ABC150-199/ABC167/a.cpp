#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;

    bool no = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) no = true;
    }

    if(!no) cout << "Yes" << endl;
    else cout << "No" <<endl;
    
    return 0;
}