#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll UNIT = 10000;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class T, class U>
T ceil(T x, U y) {
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T, class U>
T floor(T x, U y) {
    return (x > 0 ? x / y : (x - y + 1) / y);
}

// N は平方数, 0 <= N <= 4.5*10^18 < 2^62
ll integer_sqrt(ll N) {
    // √n < 2^31
    ll low = -1, high = 1LL << 31;
    while (high - low > 1) {
        ll mid = (low + high) / 2, mid2 = mid * mid;
        if (mid2 <= N) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    double X, Y, R;
    cin >> X >> Y >> R;

    // 10^4 倍して整数に直す
    ll X2 = lround(X * UNIT), Y2 = lround(Y * UNIT), R2 = lround(R * UNIT);
    ll ans = 0;
    ll left = ceil(X2 - R2, UNIT) * UNIT, right = floor(X2 + R2, UNIT) * UNIT;
    for (ll x = left; x <= right; x += UNIT) {
        ll d = integer_sqrt(R2 * R2 - (X2 - x) * (X2 - x));
        ll up = floor(Y2 + d, UNIT) * UNIT, down = ceil(Y2 - d, UNIT) * UNIT;
        ans += floor(up - down, UNIT) + 1;
    }

    cout << ans << endl;
}