#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ld = long double;
const ld PI = acos(-1);

ld to_rad(int deg){
    return (ld)(deg) * PI / 180;
}

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

        // E分後のy, z座標の値を求める
        ld y = -L / 2 * sin(to_rad(360 * E / T));
        ld z = L / 2 - L / 2 * cos(to_rad(360 * E / T));

        // 俯角を求めるために隣辺、対辺の長さを求める
        ld d1 = hypot(X, y - Y);
        ld d2 = z;

        // 俯角を求める
        ld ans = to_deg(atan2(d2, d1));
        cout << ans << "\n";
    }
    return 0;
}