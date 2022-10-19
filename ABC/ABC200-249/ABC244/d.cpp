#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<char> s(3),t(3);
    for(int i = 0; i < 3; i++) cin >> s[i];
    for(int i = 0; i < 3; i++) cin >> t[i];

    int diff = 0;
    for(int i = 0; i < 3; i++) if(s[i] != t[i]) diff++;

    if(diff == 0 || diff == 3) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}