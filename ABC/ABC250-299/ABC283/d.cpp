#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int N = S.size();
    stack<set<char>> stk;
    set<char> st;
    bool flag = true;
    stk.push({});
    for(int i = 0; i < N; i++){
        if(S[i] == '(') stk.push({});
        if('a' <= S[i] && S[i] <= 'z'){
            if(st.count(S[i])) flag = false;
            st.insert(S[i]);
            stk.top().insert(S[i]);
        }
        if(S[i] == ')'){
            for(auto c: stk.top()){
                st.erase(c);
            }
            stk.pop();
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}