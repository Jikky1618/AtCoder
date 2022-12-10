#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll X, A, D, N;
    cin >> X >> A >> D >> N;

    // 等差数列の反転
    if(D < 0){
        D *= -1;
        A = (N - 1) * D + A;
    }

    auto check  = [&](ll mid) -> bool {
        ll val = (mid - 1) * D + A;
        return val > X;
    };

    // Xを超える最小のSiを求める: ng: Xを超えない, ok: Xを超える
    ll ng = -1, ok = N + 1;
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    // cout << ok << " " << ng << endl;
    ll ans = INF;
    for(ll i = max(0ll, ok-5); i <= min(N, ok+5); i++){
        ans = min(ans, abs(X - ((i - 1) * D + A)));
    }

    cout << ans << endl;
    return 0;
}