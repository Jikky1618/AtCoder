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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i], B[i]--;

    // 園 i にいる園児のレートの集合
    const int M = 2e5 + 1;
    vector<multiset<int>> st(M);
    // 各園のレートの最大値を管理する set
    multiset<int> mx;

    for (int i = 0; i < N; i++) st[B[i]].emplace(A[i]);
    for (int i = 0; i < M; i++) if (!st[i].empty()) mx.emplace(*st[i].rbegin());

    debug(st, mx);
    while (Q--) {
        int C, D;
        cin >> C >> D, C--, D--;
        // 園　B[C] の最大値と園児 C を削除
        mx.erase(mx.find(*st[B[C]].rbegin()));
        st[B[C]].erase(st[B[C]].find(A[C]));
        // B[C] の最大値を更新
        if (!st[B[C]].empty()) mx.emplace(*st[B[C]].rbegin());

        // 園児 C を園 D に更新
        B[C] = D;

        // 園 B[C] の最大値を削除と園児 C を追加
        if (!st[B[C]].empty()) mx.erase(mx.find(*st[B[C]].rbegin()));
        st[B[C]].emplace(A[C]);
        // 園 B[C] の最大値を更新
        mx.emplace(*st[B[C]].rbegin());

        cout << *mx.begin() << '\n';
    }
}