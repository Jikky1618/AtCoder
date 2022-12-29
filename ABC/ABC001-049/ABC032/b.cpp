#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    int k;
    cin >> s >> k;

    int N = s.size();
    set<string> st;
    for(int i = 0; i < N - k + 1; i++){
        st.insert(s.substr(i, k));
    }

    cout << st.size() << endl;
    return 0;
}