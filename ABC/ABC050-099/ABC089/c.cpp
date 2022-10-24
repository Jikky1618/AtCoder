#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<ll> cnt(5); // M,A,R,C,H
    for(int i = 0; i < n; i++){
        if(s[i][0] == 'M') cnt[0]++;
        if(s[i][0] == 'A') cnt[1]++;
        if(s[i][0] == 'R') cnt[2]++;
        if(s[i][0] == 'C') cnt[3]++;
        if(s[i][0] == 'H') cnt[4]++;
    }

    ll ans = 0;
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            for(int k = j + 1; k < 5; k++){
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }

    cout << ans << endl;
    return 0;
}