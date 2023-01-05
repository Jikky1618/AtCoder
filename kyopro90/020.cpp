#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow(ll a, ll n){
    ll res = 1;
    while (n > 0){
        if (n & 1) res *= a;  // b の最下位bitが1ならばa^(2^i)をかける
        a *= a; // 変数aはa^2,a^4,a^8,...と変化
        n >>= 1;  // bを1bit左にずらす
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll a, b, c;
    cin >> a >> b >> c;
    
    // a < c^b を判定
    cout << (a < pow(c, b) ? "Yes" : "No") << endl;
    return 0;
}