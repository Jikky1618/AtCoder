#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<string> s(3);
    string t;
    cin >> s[0] >> s[1] >> s[2] >> t;

    string ans;
    for(int i = 0; i < t.length(); i++){
        ans += s[t[i]];
    }

    cout << ans << endl;

    return 0;
}