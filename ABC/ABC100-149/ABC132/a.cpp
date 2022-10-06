#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    vector<int> a(26);
    bool flag = true;
    for(int i = 0; i < 26; i++) a[s[i] - 'A']++;
    for(int i = 0; i < 26; i++){
        if(a[i] != 0 && a[i] != 2) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}