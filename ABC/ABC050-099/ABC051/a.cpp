#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;

    for(auto &&c: s) if(c == ',') c = ' ';
    cout << s << endl;
    return 0;
}