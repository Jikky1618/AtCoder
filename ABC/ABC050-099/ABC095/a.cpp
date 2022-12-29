#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int ans = 700;
    for(int i = 0; i < 3; i++) if(S[i] == 'o') ans += 100;

    cout << ans << endl;
    return 0;
}