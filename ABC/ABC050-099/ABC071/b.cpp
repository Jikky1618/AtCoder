#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    set<char> st;
    for(auto s: S) st.insert(s);

    for(int i = 0; i < 26; i++){
        char c = (char)('a' + i);
        if(!st.count(c)){
            cout << c << endl;
            return 0;
        }
    }

    cout << "None" << endl;
    return 0;
}