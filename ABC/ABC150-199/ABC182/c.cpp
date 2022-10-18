#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string n;
    cin >> n;

    int k = n.size();

    int ans = INF;
    for(int bit = 0; bit < (1 << k); bit++){
        string s = n;
        for(int i = 0; i < k; i++){
            if(!((bit >> i) & 1)){
                s[i] = 0;
            }
        }
        int sum = 0;
        for(auto i:s) sum += (i - '0');
        if(sum % 3 == 0) ans = min(ans, k -  __builtin_popcount(bit));
    }

    if(ans == k) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}