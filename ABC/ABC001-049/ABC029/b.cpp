#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<string> S(12);
    for(int i = 0; i < 12; i++) cin >> S[i];

    int ans = 0;
    for(int i = 0; i < 12; i++) if(S[i].find('r') != string::npos) ans++;

    cout << ans << endl;
    return 0;
}