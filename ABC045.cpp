#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();

    ll ans = 0;
    for(int bit = 0; bit < (1 << (n - 1)); bit++){
        ll sum = 0;
        ll num = s[0] - '0';
        for(int i = 0; i < n - 1; i++){
            if((bit >> i) & 1){
                sum += num;
                num = 0;
            }
            num = num * 10 + s[i + 1] - '0';
        }
        sum += num;
        ans += sum;
    }

    cout << ans << endl;
    return 0;
}