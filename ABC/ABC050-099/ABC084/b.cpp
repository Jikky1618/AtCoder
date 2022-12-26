#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B; string S;
    cin >> A >> B >> S;

    bool flag = true;
    for(int i = 0; i < A; i++){
        if('0' <= S[i] && S[i] <= '9') continue;
        flag = false;
    }
    if(S[A] != '-') flag = false;
    for(int i = A + 1; i < A + B + 1; i++){
        if('0' <= S[i] && S[i] <= '9') continue;
        flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}