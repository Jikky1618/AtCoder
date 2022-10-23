#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    int ans = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i - 1]) ans++;
    }

    cout << ans << endl;
    return 0;
}