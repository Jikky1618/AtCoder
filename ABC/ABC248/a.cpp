#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;

    vector<bool> flag(10);
    for(int i = 0; i < 9; i++){
        flag[s[i] - '0'] = true;
    }

    for(int i = 0; i < 10; i++){
        if(!flag[i]) cout << i << endl;
    }

    return 0;
}