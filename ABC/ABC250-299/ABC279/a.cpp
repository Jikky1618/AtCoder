#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'v') ans++;
        if(s[i] == 'w') ans += 2;
    }

    cout << ans << endl;
    return 0;
}