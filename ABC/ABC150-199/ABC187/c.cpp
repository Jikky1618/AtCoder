#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    set<string> st;
    for(int i = 0; i < n; i++) st.insert(s[i]);

    for(int i = 0; i < n; i++){
        if(st.count(s[i]) && st.count('!' + s[i])){
            cout << s[i] << endl;
            return 0;
        }
    }

    cout << "satisfiable" << endl;
    return 0;
}