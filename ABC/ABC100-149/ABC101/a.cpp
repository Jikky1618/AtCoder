#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;
    
    int ans = 0;
    for(auto c: S) ans += (c == '+' ? 1 : -1);
    cout << ans << endl;
    return 0;
}