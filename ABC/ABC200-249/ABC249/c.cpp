#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        vector<int> sum(26); // alphabet
        for(int i = 0; i < n; i++){
            if((bit >> i) & 1){
                for(auto x: s[i]){
                    sum[x - 'a']++;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(sum[i] == k) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}