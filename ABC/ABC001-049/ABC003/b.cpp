#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S, T;
    cin >> S >> T;

    int N = S.size();

    string a = "atcoder";
    bool flag = true;
    for(int i = 0; i < N; i++){
        if(S[i] == '@' && T[i] == '@') continue;
        if(S[i] == '@' && a.find(T[i]) == string::npos) flag = false;
        if(T[i] == '@' && a.find(S[i]) == string::npos) flag = false;
        if(S[i] != '@' && T[i] != '@' && S[i] != T[i]) flag = false;
    }

    cout << (flag ? "You can win" : "You will lose") << endl;
    return 0;
}