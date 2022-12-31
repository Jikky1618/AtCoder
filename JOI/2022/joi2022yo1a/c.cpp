#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;

    set<char> st;
    for(auto c: S) st.insert(c);
    
    cout << (st.size() >= 3 ? "Yes" : "No") << endl;
    return 0;
}