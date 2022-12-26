#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    bool flag = true;

    if(S.front() != 'A') flag = false;

    int N = S.size();
    int cnt = 0;
    for(int i = 2; i < N - 1; i++){
        if(S[i] == 'C') cnt++;
    }
    if(cnt != 1) flag = false;

    for(int i = 1; i < N; i++){
        if('a' <= S[i] && S[i] <= 'z' || S[i] == 'C') continue;
        flag = false;
    }

    if(flag) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}