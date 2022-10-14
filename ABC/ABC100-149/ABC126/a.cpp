#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    int n,k;
    cin >> n >> k >> s;

    s[k - 1] = tolower(s[k - 1]);

    cout << s << endl;
    return 0;
}