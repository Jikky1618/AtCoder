#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string w;
    cin >> w;

    map<char, int> mp;
    for(auto c: w) mp[c]++;

    bool flag = true;
    for(auto[key, val]: mp){
        if(val % 2 == 1) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}