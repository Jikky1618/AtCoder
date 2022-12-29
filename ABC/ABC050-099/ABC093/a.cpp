#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;
    
    sort(S.begin(), S.end());
    cout << (S == "abc" ? "Yes" : "No") << endl;
    return 0;
}