#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> A(3);
    for(int i = 0; i < 3; i++) cin >> A[i];

    map<int, int> mp;
    for(int i = 0; i < 3; i++) mp[A[i]]++;
    for(auto[key, val]: mp) if(val == 1) cout << key << endl;

    return 0;
}