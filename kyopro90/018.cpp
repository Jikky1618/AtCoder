#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const double PI = acos(-1);

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

ld to_deg(ld rad){
    return rad * 180 / PI;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ld T, L, X, Y;
    cin >> T >> L >> X >> Y;
    int Q;
    cin >> Q;

    while(Q--){
        ld E; cin >> E;
        // 観覧車のy, z座標を求める
        ld y = -L / 2 * sin(E / T * 2 * PI);
        ld z = -L / 2 * cos(E / T * 2 * PI) + L / 2;
        
        // 隣辺aと対辺bを求める
        ld a = z;
        ld b = hypot(X, Y - y);

        // 俯角を求める
        ld ans = to_deg(atan2(a, b));
        cout << ans << '\n';
    }
}