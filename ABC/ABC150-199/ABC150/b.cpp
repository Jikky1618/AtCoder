#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 0; i < n - 2; i++){
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') ans++;
    }

    cout << ans << endl;
    
    return 0;
}