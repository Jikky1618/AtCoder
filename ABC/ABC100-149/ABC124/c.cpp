#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int n = s.size();

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[0] == '1'){
            if(i % 2 == 0 && s[i] == '0') ans++;
            if(i % 2 == 1 && s[i] == '1') ans++;
        }else{
            if(i % 2 == 0 && s[i] == '1') ans++;
            if(i % 2 == 1 && s[i] == '0') ans++;
        }
    }

    cout << ans << endl;
    return 0;
}