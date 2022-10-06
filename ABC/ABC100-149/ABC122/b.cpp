#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    string t = "ACGT";
    int n = s.size();

    int ans = 0,cnt = 0;
    for(int i = 0; i < n; i++){
        if(t.find(s[i]) == -1) cnt = 0;
        else cnt++;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}