#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int T;
    cin >> T;

    while (T--) {
        vector<int> x(3);
        for (int i = 0; i < 3; i++) cin >> x[i];
        sort(x.begin(), x.end());
        auto [d1, d2] = minmax({x[1] - x[0], x[2] - x[1]});
        int c = d2 - d1;
        // d1, d2 が偶数かつ, c = d2 - d1 が 6 の倍数でなければ, 不可能
        if ((d1 & 1) || (d2 & 1) || c % 6 != 0) {
            cout << -1 << '\n';
        } else {
            cout << d1 / 2 + c / 3 << '\n';
        }
    }
}