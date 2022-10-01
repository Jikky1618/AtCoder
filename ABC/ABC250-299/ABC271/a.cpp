#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N進数(string) -> 10進数(ll)
ll n_to_dec(string x,ll n){
    ll ans = 0, base = 1, size = x.size();
    for(int i = size - 1; i >= 0; i--){
        ans += 1LL * (x[i] - '0') * base;
        base *= n;
    }
    return ans;
}

// 10進数(ll) -> N進数(string)
string dec_to_n(ll num, ll n){
    if(num == 0) return "0";
    string ans; char c;
    while(num > 0){
        if(num % n < 10) c = ((num % n) + '0');
        else c = ((num % n) + 'A' - 10);
        ans = c + ans;
        num /= n;
    }
    return ans;
}

// N進数(string) -> M進数(string)
string drc(string str, int n, int m){
    return dec_to_n(n_to_dec(str, n), m);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    
    s = drc(s, 10, 16);
    if(s.size() == 1) cout << "0" << s << endl;
    else cout << s << endl;
    return 0;
}