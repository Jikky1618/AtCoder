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
    // S -> T が一対一対応しているか
    map<char, char> mp1, mp2;
    for(int i = 0; i < N; i++){
        if(!mp1.count(S[i])) mp1[S[i]] = T[i];
        if(!mp2.count(T[i])) mp2[T[i]] = S[i];
    }

    bool flag = true;
    for(int i = 0; i < N; i++){
        // 異なる変換先or変換元があればfalse
        if(mp1[S[i]] != T[i]) flag = false;
        if(mp2[T[i]] != S[i]) flag = false;
    }

    cout << (flag ? "Yes" : "No") << endl;
}