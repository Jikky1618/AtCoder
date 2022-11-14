#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n,x;
    string s;
    cin >> n >> x >> s;

    string t;
    for(auto &&c: s){
        if(t.size() && t.back() != 'U' && c == 'U'){
            t.pop_back();
        }else{
            t += c;
        }
    }

    ll ans = x;
    for(auto &&c: t){
        if(c == 'U') ans /= 2;
        if(c == 'L') ans *= 2;
        if(c == 'R') ans = ans * 2 + 1;
    }

    cout << ans << endl;
    return 0;
}