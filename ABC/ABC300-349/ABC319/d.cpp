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
    ll N, M;
    cin >> N >> M;
    vector<ll> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];

    auto check = [&](ll mid) -> bool {
        ll pos = 0, len = L[0];
        for (int i = 1; i < N; i++) {
            // 右に置けるなら置く
            if (len + L[i] + 1 <= mid) {
                len += L[i] + 1;
            // 置けないなら下の行に置く
            } else {
                len = L[i];
                pos++;
            }
        }
        return pos < M && len <= mid;
    };

    ll ok = reduce(L.begin(), L.end()) + N, ng = *max_element(L.begin(), L.end()) - 1;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << ok << endl;
}