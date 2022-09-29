#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();

    bool judge = true;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0 && s[i] == 'L') judge = false;
        if(i % 2 == 1 && s[i] == 'R') judge = false;
    }

    if(judge) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}