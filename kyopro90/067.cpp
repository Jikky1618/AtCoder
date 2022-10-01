#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n_to_dec(string x,ll n){
    ll ans = 0, base = 1, size = x.size();
    for(int i = size - 1; i >= 0; i--){
        ans += 1LL * (x[i] - '0') * base;
        base *= n;
    }
    return ans;
}

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

string drc(string str, int n, int m){
    return dec_to_n(n_to_dec(str, n), m);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string n;
    ll k;
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        n = drc(n,8,9);
        for(int i = 0; i < n.size(); i++){
            if(n[i] == '8') n[i] = '5';
        }
    }

    cout << n << endl;
    return 0;
}