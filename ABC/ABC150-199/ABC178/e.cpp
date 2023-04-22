#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];

    // u[i] := x[i] + y[i], v[i] := x[i] - y[i]
    vector<ll> u(N), v(N);
    ll min_u = INF, min_v = INF, max_u = -INF, max_v = -INF;
    for(int i = 0; i < N; i++){
        u[i] = x[i] + y[i];
        v[i] = x[i] - y[i];
        min_u = min(min_u, u[i]);
        min_v = min(min_v, v[i]);
        max_u = max(max_u, u[i]);
        max_v = max(max_v, v[i]);
    }

    // 距離はmax(|u1 - u2|, |v1 - v2|)
    ll ans = max(abs(max_u - min_u), abs(max_v - min_v));
    cout << ans << endl;
}