#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;

    ll ans = K;
    for(int i = 1; i < N; i++) ans *= (K - 1);

    cout << ans << endl;
    return 0;
}