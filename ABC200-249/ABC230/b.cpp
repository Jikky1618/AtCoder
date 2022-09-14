#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S,T;
    cin >> S;
    for(int i = 0; i < 10; i++) T += "oxx";

    for(int i = 0; i < 10; i++){
        if(S == T.substr(i,S.size())){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}