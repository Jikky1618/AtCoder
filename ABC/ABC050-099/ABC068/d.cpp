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
    ll K;
    cin >> K;

    const ll N = 50;
    // ゴールから逆算する {N - 1, N - 1, ..., N - 1} から逆の操作を K 回繰り返す
    // 重大な考察: 全ての要素に操作を施すと, 全ての要素が +1 となる
    // その回数を ave とし, 残りを remain とする
    ll ave = K / N, remain = K % N;
    vector<ll> ans(N, N - 1);
    // remain 個の要素は N - 1 + ave + N - (remain - 1) となる
    for (int i = 0; i < remain; i++) ans[i] = N - 1 + ave + N - (remain - 1);
    // N - remain 個の要素は N - 1 + ave - remain となる
    for (int i = remain; i < N; i++) ans[i] = N - 1 + ave - remain;

    cout << N << '\n';
    for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}