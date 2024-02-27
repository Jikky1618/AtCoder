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
template <class T, class F>
struct SegmentTree {
    int n, ls;
    vector<T> data;
    const F op;
    const T id;

    SegmentTree() = default;
    SegmentTree(int size, const F& operation, const T& identify) : n(size), op(operation), id(identify) { init(); }
    SegmentTree(const vector<T>& v, const F& operation, const T& identify) : n(int(v.size())), op(operation), id(identify) { init(), build(v); }
    void init() {
        ls = 1;
        while (ls < n) ls <<= 1;
        data.assign(ls << 1, id);
    }
    void build(const vector<T>& v) {
        for (int i = 0; i < n; i++) data[i + ls] = v[i];
        for (int i = ls - 1; i > 0; i--) data[i] = op(data[i << 1 | 0], data[i << 1 | 1]);
    }
    void update(int i, T x) {
        i += ls, data[i] = x;
        while(i > 1) {
            i >>= 1;
            data[i] = op(data[i << 1 | 0], data[i << 1 | 1]);
        }
    }
    T prod(int l, int r) const {
        l += ls, r += ls;
        T resl = id, resr = id;
        while(l < r) {
            if(l & 1) resl = op(resl, data[l++]);
            if(r & 1) resr = op(data[--r], resr);
            l >>= 1, r >>= 1;
        }
        return op(resl, resr);
    }
    T prod_all() const { return data[1]; }
    T operator[](int i) const { return data[i + ls]; }

    // check(v[l] * ... * v[r - 1]) = true となる最大の r
    template <class C>
    int max_right(int l, const C& check) const {
        assert(0 <= l && l <= n && check(id));
        if (l == n) return n;
        l += ls;
        T sum = id;
        do {
            while (l % 2 == 0) l >>= 1;
            // data[l] を追加しても true なら加算
            if (!check(op(sum, data[l]))) {
                // 根に到達するまで加算
                while (l < ls) {
                    l = l << 1 | 0;
                    // data[l] を追加しても true なら加算して右の子に移動
                    if (check(op(sum, data[l]))) {
                        sum = op(sum, data[l++]);
                    }
                }
                return l - ls;
            }
            sum = op(sum, data[l++]);
        } while ((l & -l) != l);
        return n;
    }

    // check(v[l] * ... * v[r - 1]) = true となる最小の l
    template <class C>
    int min_left(int r, const C& check) const {
        assert(0 <= r && r <= n && check(id));
        if (r == 0) return 0;
        r += ls;
        T sum = id;
        do {
            --r;
            while (r > 1 && r % 2) r >>= 1;
            if (!check(op(data[r], sum))) {
                while (r < ls) {
                    r = r << 1 | 1;
                    if (check(op(data[r], sum))) {
                        sum = op(data[r--], sum);
                    }
                }
                return r + 1 - ls;
            }
            sum = op(data[r], sum);
        } while ((r & -r) != r);
        return 0;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N; ll C;
    cin >> N >> C;
    vector<ll> x(N), v(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> v[i];

    ll val = 0;
    // i 番目まで時計回りに回ったときの獲得したエネルギー
    vector<ll> left(N), right(N);
    for(int i = 0; i < N; i++){
        val += v[i];
        val -= (i == 0 ? x[i] : x[i] - x[i - 1]);
        left[i] = val;
    }
    // 反時計回りに回ったとき
    val = 0;
    for(int i = N - 1; i >= 0; i--){
        val += v[i];
        val -= (i == N - 1 ? C - x[i] : x[i + 1] - x[i]);
        right[i] = val;
    }

    auto op = [](ll a, ll b){return max(a, b);};
    SegmentTree<ll, decltype(op)> L(left, op, 0);
    SegmentTree<ll, decltype(op)> R(right, op, 0);
    ll ans = max({0LL, L.prod_all(), R.prod_all()});
    for(int i = 0; i < N; i++){
        // i 個目まで時計回り -> 反時計回り
        val = left[i] - x[i] + R.prod(i + 1, N);
        debug(val);
        ans = max(ans, val);
        // i 個目まで反時計回り -> 時計回り
        val = right[i] - (C - x[i]) + L.prod(0, i);
        debug(val);
        ans = max(ans, val);
    }
    debug(left, right);

    cout << ans << '\n';
}