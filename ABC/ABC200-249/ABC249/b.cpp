#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;

    bool upper = false,lower = false;
    for(int i = 0; i < s.length(); i++){
        if('a' <= s[i] && s[i] <= 'z') lower = true;
        if('A' <= s[i] && s[i] <= 'Z') upper = true;
    }
    // bool diff = true;
    //     for(int i = 0; i < s.size(); i++){
    //         for(int j = i + 1; j < s.size(); j++){
    //             if(s[i] == s[j]) diff = false;
    //         }
    //     }
    set<int> st;
    bool diff = false;
    for(int i = 0; i < s.length(); i++){
        st.insert(s[i] - '0');
    }
    if(st.size() == s.length()) diff = true;

    if(upper && lower && diff) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}