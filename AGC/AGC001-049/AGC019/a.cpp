#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;

    ll ans = 0;
    // 2リットルあたりの値段
    vector<ll> p = {8 * Q, 4 * H, 2 * S, D};
    sort(p.begin(), p.end());
    ans += p[0] * (N / 2), N %= 2;

    // 1リットルあたりの値段
    vector<ll> p2 = {4 * Q, 2 * H, S};
    sort(p2.begin(), p2.end());
    ans += p2[0] * N;

    cout << ans << endl;
    return 0;
}