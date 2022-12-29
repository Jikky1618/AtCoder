#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<char> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    set<char> st;
    for(int i = 0; i < N; i++) st.insert(S[i]);

    cout << (st.size() == 3 ? "Three" : "Four") << endl;
    return 0;
}