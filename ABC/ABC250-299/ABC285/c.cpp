#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;
    
    ll ans = 0, base = 1;
    for(int i = S.size() - 1; i >= 0; i--){
        ans += 1LL * (S[i] - 'A' + 1) * base;
        base *= 26;
    }

    cout << ans << endl;
}