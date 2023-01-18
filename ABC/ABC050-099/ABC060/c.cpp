#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, T;
    cin >> N >> T;
    vector<ll> t(N);
    for(int i = 0; i < N; i++) cin >> t[i];

    ll ans = 0;
    for(int i = 0; i < N - 1; i++){
        ans += min(T, t[i + 1] - t[i]);
    }
    ans += T; // 最後の人

    cout << ans << endl;
}