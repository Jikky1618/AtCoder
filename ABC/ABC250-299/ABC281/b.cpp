#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_upper(char &C){
    return ('A' <= C && C <= 'Z');
}


bool is_number(char &C){
    return ('0' <= C && C <= '9');
}

bool is_six_number(string &S){
    if(S.size() != 8) return false;
    for(int i = 1; i < 6; i++) if(!is_number(S[i])) return false;

    int N = stoi(S.substr(1,6));
    return (100000 <= N && N <= 999999);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    bool flag = true;
    if(!is_upper(S.front()) || !is_upper(S.back())) flag = false;
    if(!is_six_number(S)) flag = false;

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}