#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int N = S.size();
    map<char, int> mp;
    for(int i = 0; i < N; i++){
        mp[S[i]]++;
    }

    bool flag = true;
    for(auto[key, val]: mp){
        if(key == 'S' && mp['N'] == 0) flag = false;
        if(key == 'N' && mp['S'] == 0) flag = false;
        if(key == 'E' && mp['W'] == 0) flag = false;
        if(key == 'W' && mp['E'] == 0) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}