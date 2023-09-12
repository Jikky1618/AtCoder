#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-14;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ld X, Y, R;
    cin >> X >> Y >> R, R += eps;

    ll ans = 0;
    ld left = ceill(X - R), right = floorl(X + R);
    for(ld x = left; x <= right; x += 1.0){
        ld d = sqrtl(R * R - (X - x) * (X - x));
        ld top = floorl(Y + d), bottom = ceill(Y - d);
        ans += ll(top - bottom) + 1;
    }

    cout << ans << endl;
}