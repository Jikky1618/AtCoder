#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;

    string ans = "";
    for(auto c: s){
        if(c == '0') ans.push_back('0');
        if(c == '1') ans.push_back('1');
        if(c == 'B' && !ans.empty()) ans.pop_back();
    }

    cout << ans << endl;
    return 0;
}