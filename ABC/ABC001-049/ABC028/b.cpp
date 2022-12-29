#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;
    map<char, int> mp;
    for(auto c: S) mp[c]++;

    for(int i = 0; i < 6; i++) cout << mp['A' + i] << (i == 5 ? "\n" : " ");
    return 0;
}