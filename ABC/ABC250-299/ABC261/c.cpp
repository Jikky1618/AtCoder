#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    map<string,int> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
        if(mp[s[i]] > 1) cout << s[i] << "(" << mp[s[i]] - 1 << ")" << endl;
        else cout << s[i] << endl;
    }

    return 0;
}