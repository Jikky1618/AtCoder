#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    int N, M;
    cin >> N >> M;
    vector<int> l(N), r(N), s(N);
    for (int i = 0; i < N; i++) cin >> l[i] >> r[i] >> s[i];

    // 101点解法
    // imos法
    vector<int> imos(M + 1);
    for (int i = 0; i < N; i++) {
        imos[l[i] - 1] += s[i];
        imos[r[i]] -= s[i];
    }
    for (int i = 0; i < M - 1; i++) imos[i + 1] += imos[i];

    int ans = 0;
    for (int i = 0; i < N; i++) ans += s[i];

    // imos法を行った配列内で最も小さい要素を答えから引く(選ばない宝石)
    int Min = INF;
    for (int i = 0; i < M; i++) Min = min(Min, imos[i]);
    ans -= Min;

    cout << ans << endl;
}