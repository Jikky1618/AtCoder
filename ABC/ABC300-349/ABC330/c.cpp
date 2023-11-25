#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll D;
    cin >> D;

    // x を全探索
    ll ans = INF;
    for (ll x = 0; x * x <= D; x++) {
        // C は負の値になる (正の値だと最適解にならない)
        ll C = x * x - D;
        // -C 以下の最も大きい平方数 y^2 の y を求める
        ll y = llround(sqrt(-C));
        ans = min(ans, abs(y * y + C));
        ans = min(ans, abs((y + 1) * (y + 1) + C));
    }

    cout << ans << '\n';
}