#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<string> s(3);
    for(int i = 0; i < 3; i++) cin >> s[i];
    for(int i = 0; i < 3; i++) cout << (char)toupper(s[i].front());
    cout << endl;
    return 0;
}