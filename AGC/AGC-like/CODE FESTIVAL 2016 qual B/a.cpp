#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    string A = "CODEFESTIVAL2016";
    int ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] != A[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}