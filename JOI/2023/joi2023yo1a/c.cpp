#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    string s;
    cin >> n >> s;

    int ans = 0, cnt = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') cnt = max(1, cnt - 1);
        if(s[i] == 'R') cnt = min(3, cnt + 1);
        if(cnt == 3) ans++;
    }

    cout << ans << endl;
    return 0;
}