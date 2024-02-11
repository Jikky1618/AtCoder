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

template <class T, class F>
struct SegmentTree {
    int n;
    vector<T> data;
    const F op;
    const T id;

    SegmentTree(int size, const F& operation, const T& identity) : op(operation), id(identity) {
        n = 1;
        while (n < size) n <<= 1;
        data.assign(n << 1, id);
    }
    SegmentTree(const vector<T>& v, const F& operation, const T& identity) : op(operation), id(identity) {
        n = 1;
        while (n < int(v.size())) n <<= 1;
        data.assign(n << 1, id);
        build(v);
    }
    void build(const vector<T>& v) {
        for (int i = 0; i < int(v.size()); i++) data[i + n] = v[i];
        for (int i = n - 1; i > 0; i--) data[i] = op(data[i << 1 | 0], data[i << 1 | 1]);
    }
    void update(int i, T x) {
        i += n;
        data[i] = x;
        while (i > 1) {
            i >>= 1;
            data[i] = op(data[i << 1 | 0], data[i << 1 | 1]);
        }
    }
    T prod(int l, int r) const {
        l += n, r += n;
        T resl = id, resr = id;
        while (l < r) {
            if (l & 1) resl = op(resl, data[l++]);
            if (r & 1) resr = op(data[--r], resr);
            l >>= 1, r >>= 1;
        }
        return op(resl, resr);
    }
    T operator[](int i) const { return data[i + n]; }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i], P[i]--;

    auto op = [](int a, int b) { return max(a, b); };
    auto op2 = [](int a, int b) { return min(a, b); };
    vector<int> ans(N, INF);
    SegmentTree seg1(N, op, -INF);
    SegmentTree seg2(N, op2, INF);
    for (int i = 0; i < N; i++) {
        // P[i] + i - max(P[j] + j)
        ans[i] = min(ans[i], P[i] + i - seg1.prod(0, P[i]));
        seg1.update(P[i], P[i] + i);
        // min(P[j] + j) - (P[i] - i)
        ans[i] = min(ans[i], seg2.prod(P[i] + 1, N) - (P[i] - i));
        seg2.update(P[i], P[i] - i);
    }

    SegmentTree seg3(N, op, -INF);
    SegmentTree seg4(N, op2, INF);
    for (int i = N - 1; i >= 0; i--) {
        // P[i] - i - max(P[j] - j)
        ans[i] = min(ans[i], P[i] - i - seg3.prod(0, P[i]));
        seg3.update(P[i], P[i] - i);
        // min(P[j] + j) - (P[j] + i)
        ans[i] = min(ans[i], seg4.prod(P[i] + 1, N) - (P[i] + i));
        seg4.update(P[i], P[i] + i);
    }

    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}