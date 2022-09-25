#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;

    int diff = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) diff++;
    }

    cout << diff << endl;
    
    return 0;
}