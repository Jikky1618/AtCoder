#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    ll ans = 0;
    for(ll A = 1; A * A * A <= N; A++){
        for(ll B = A; B <= N / (A * B); B++){
            ans += N / (A * B) - B + 1;
        }
    }

    cout << ans << endl;
    return 0;
}