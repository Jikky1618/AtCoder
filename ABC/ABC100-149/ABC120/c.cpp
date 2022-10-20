#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int r = 0, b = 0;
    for(auto c: s){
        if(c == '0') r++;
        else b++;
    }
    
    cout << min(r, b) * 2 << endl;
    return 0;
}