#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;


    while(S.size()){
        if(S[S.size() - 2] == 'c' && S[S.size() - 1] == 'h') S.pop_back(), S.pop_back();
        else if(S.back() == 'o') S.pop_back();
        else if(S.back() == 'k') S.pop_back();
        else if(S.back() == 'u') S.pop_back();
        else{
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}