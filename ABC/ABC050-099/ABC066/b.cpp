#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    while(S.size() > 0){
        S.pop_back();
        if(S.substr(0, S.size() / 2) == S.substr(S.size() / 2)){
            cout << S.size() << endl;
            return 0;
        }
    }
    return 0;
}