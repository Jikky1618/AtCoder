#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s,t;
    cin >> s >> t;

    for(int i = 0; i < 26; i++){
        string s_ = s;
        for(int j = 0; j < (int)s.size(); j++){
            // (s[j] - 'a') is int
            s_[j] = (((s[j] - 'a') + i) % 26) + 'a';
        }
        if(s_ == t){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}