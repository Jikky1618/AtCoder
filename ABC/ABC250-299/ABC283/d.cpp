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
    set<pair<char, int>> st; // アルファベットを管理
    bool flag = true;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == '(') cnt++;
        if('a' <= S[i] && S[i] <= 'z'){
            if(st.count({S[i], cnt})) flag = false;
            st.insert({S[i], cnt});
        }
        if(S[i] == ')'){
            cnt--;
        }

        if(!flag){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}