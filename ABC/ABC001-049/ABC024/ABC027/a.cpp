#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> l(3);
    for(int i = 0; i < 3; i++) cin >> l[i];

    map<int, int> mp;
    for(int i = 0; i < 3; i++) mp[l[i]]++;

    for(auto[key, val]: mp) if(val == 1 || val == 3) cout << key << endl;
    return 0;
}