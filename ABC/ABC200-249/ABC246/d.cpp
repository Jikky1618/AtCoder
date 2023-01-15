#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

ll f(ll a, ll b){
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    ll ans = INF;
    // aを固定して全探索
    for(ll a = 0; a <= 1e6; a++){
        // bを二分探索
        ll ok = 1e6, ng = -1;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            if(N <= f(a, mid)) ok = mid;
            else ng = mid;
        }
        ans = min(ans, f(a, ok));
    }

    cout << ans << endl;
}