#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<string> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];

    set<string> st;
    bool flag = true;
    for(int i = 0; i < N; i++){
        if(st.count(W[i])) flag = false;
        st.insert(W[i]);
        if(i < N - 1) if(W[i].back() != W[i + 1].front()) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}