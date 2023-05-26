#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    N++;
    ll ans = 0;
    while(N){
        if(N < 10) ans += N - 1;
        else ans += 9;
        N /= 10;
    }

    cout << ans << endl;
    return 0;
}