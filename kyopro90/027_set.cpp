#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    set<string> st;
    for(int i = 0; i < N; i++){
        if(st.count(S[i])) continue;
        st.insert(S[i]);
        cout << i + 1 << endl;
    }
    return 0;
}