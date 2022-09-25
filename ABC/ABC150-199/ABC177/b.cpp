#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1 << 29;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;

    int ans = INF;
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        int diff = 0;
        for(int j = 0; j < t.size(); j++){
            if(t[j] != s[i + j]) diff++;
        }
        ans = min(ans,diff);
    }

    cout << ans << endl;

    return 0;
}