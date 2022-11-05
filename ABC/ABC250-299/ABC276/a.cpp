#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    
    int ans = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a') ans = i+1;
    }

    cout << ans << endl;
    return 0;
}