#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    
    ll ans = h * w / 2;
    if(h % 2 && w % 2){
        ans++;
    }
    // コーナーケース
    if(h == 1 || w == 1){
        ans = 1;
    }

    cout << ans << endl;

    return 0;
}