#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, A, B;
    cin >> N >> A >> B;

    ll ans = INF;
    if((B - A) % 2 == 0) ans = (B - A) / 2;
    else ans = min((A + B - 1) / 2, (2 * N - A - B + 1) / 2); 

    cout << ans << endl;
    return 0;
}