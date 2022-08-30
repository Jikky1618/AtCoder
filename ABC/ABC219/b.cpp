#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<string> s(3);
    string t;
    cin >> s[0] >> s[1] >> s[2] >> t;

    string ans = "";
    for(int i = 0; i < t.size(); i++){
        // s[t[i](char) - '1'(char)]
        // 1 is not type int
        ans += s[t[i] - '1'];
    }

    cout << ans << endl;

    return 0;
}