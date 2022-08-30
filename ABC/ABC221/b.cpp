#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s,t;
    cin >> s >> t;

    bool can = false;
    if(s == t) can = true;

    for(int i = 0; i < s.size() - 1; i++){
        string s_swap = s;
        swap(s_swap[i],s_swap[i + 1]);
        if(s_swap == t) can = true;
    }
    
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}