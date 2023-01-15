#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    ll cnt = 0, ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'W'){
            cnt++, ans += i;
        }
    }

    ll p = cnt * (cnt - 1) / 2;
    cout << ans - p << endl;
}