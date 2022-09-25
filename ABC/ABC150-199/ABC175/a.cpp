#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    
    int ans = 0,streak = 0;
    for(int i = 0; i < 3; i++){
        if(s[i] == 'R') streak++;
        else streak = 0;
        ans = max(ans,streak);
    }

    cout << ans << endl;
    
    return 0;
}