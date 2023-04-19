#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MAX = 2e5 + 1;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, W;
    cin >> N >> W;
    vector<ll> S(N), T(N), P(N);
    for (int i = 0; i < N; i++) cin >> S[i] >> T[i] >> P[i];

    vector<ll> imos(MAX + 1);
    for (int i = 0; i < N; i++) {
        imos[S[i]] += P[i];
        imos[T[i]] -= P[i];
    }
    for (int i = 0; i < MAX; i++) imos[i + 1] += imos[i];

    bool flag = true;
    debug(imos);
    for (int i = 0; i < MAX; i++)
        if (W < imos[i]) flag = false;

    cout << (flag ? "Yes" : "No") << endl;
}