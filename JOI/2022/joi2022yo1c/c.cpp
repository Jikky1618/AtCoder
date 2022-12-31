#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    string S;
    cin >> N >> K >> S;

    map<char, int> mp;
    for(auto c: S) mp[c]++;

    cout << (mp['R'] == K ? "W" : "R") << endl;
    return 0;
}