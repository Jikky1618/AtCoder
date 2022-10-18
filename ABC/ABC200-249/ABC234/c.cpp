#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string dec_to_n(ll num, ll n){
    if(num == 0) return "0";
    string ans;
    while(num > 0){
        char c = ((num % n) + '0');
        ans = c + ans;
        num /= n;
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll k;
    cin >> k;

    string bit = dec_to_n(k, 2);

    string ans;
    for(int i = 0; i < bit.size(); i++){
        if(bit[i] & 1) ans += "2";
        else ans += "0";
    }

    cout << ans << endl;
    return 0;
}