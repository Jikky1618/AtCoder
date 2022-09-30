#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    map<int,int> mp;
    int ans = 0, now = 0;
    for(int i = 0; i < n; i++){
        if(mp[c[i]] == 0) now++;
        mp[c[i]]++;
        if(k <= i){
            mp[c[i - k]]--;
            if(mp[c[i - k]] == 0) now--;
        }
        ans = max(ans,now);
    }

    cout << ans << endl;
    return 0;
}