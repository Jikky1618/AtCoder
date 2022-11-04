#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string x;
    int n;
    cin >> x >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    // X文字列 -> 普通の文字列 
    map<char,char> mp1;
    for(int i = 0; i < 26; i++) mp1[x[i]] = 'a' + i;

    for(auto &&str: s){
        for(auto &&c: str) c = mp1[c];
    }
    sort(s.begin(), s.end());
    
    // 普通の文字列 -> X文字列
    map<char,char> mp2;
    for(int i = 0; i < 26; i++) mp2['a' + i] = x[i];

    for(auto &&str: s){
        for(auto &&c: str) c = mp2[c];
    }

    for(auto &&str: s) cout << str << endl;
    return 0;
}