#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string N;
    cin >> N;

    set<char> st;
    for(int i = 0; i < 4; i++) st.insert(N[i]);

    cout << (st.size() == 1 ? "SAME" : "DIFFERENT") << endl;
    return 0;
}