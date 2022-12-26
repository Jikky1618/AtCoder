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

    if(st.size() == S.size()){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;
}