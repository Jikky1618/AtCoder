#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    map<string, int> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }

    int cnt = 0;
    for(auto &&i: mp){
        if(cnt < i.second) cnt = i.second;
    }

    for(auto &&i:mp){
        if(i.second == cnt) cout << i.first << endl;
    }
    return 0;
}