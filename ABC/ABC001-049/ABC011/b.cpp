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
    for(int i = 0; i < N; i++){
        if(i == 0) cout << (char)toupper(S[i]);
        else cout << (char)tolower(S[i]);
    }
    cout << endl;
    return 0;
}