#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class Monoid>
struct SegmentTree {
    int n;
    vector<Monoid> dat;
    function<Monoid(Monoid, Monoid)> op;
    Monoid id;

    SegmentTree(int size, function<Monoid(Monoid, Monoid)> operation, Monoid identity)
        : op(operation), id(identity) {
        n = 1;
        while (n < size) n <<= 1;
        dat.resize(2 * n - 1, id);
    }

    SegmentTree(const vector<Monoid>& vec, function<Monoid(Monoid, Monoid)> operation, Monoid identity)
        : op(operation), id(identity) {
        n = 1;
        while (n < int(vec.size())) n <<= 1;
        dat.resize(2 * n - 1, id);
        for (int i = 0; i < int(vec.size()); i++) {
            dat[i + n - 1] = vec[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    void update(int k, Monoid x) {
        k += n - 1;
        dat[k] = x;
        while (k > 0) {
            k = (k - 1) >> 1;
            dat[k] = op(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    // 再帰関数による区間取得
    Monoid get(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return id;
        if (a <= l && r <= b) return dat[k];

        Monoid vl = get(a, b, k * 2 + 1, l, (l + r) >> 1);
        Monoid vr = get(a, b, k * 2 + 2, (l + r) >> 1, r);
        return op(vl, vr);
    }

    // 区間[a, b)の取得
    Monoid get(int a, int b) {
        return get(a, b, 0, 0, n);
    }

    // 一点取得
    Monoid operator [] (int k) const {
        return dat[k + n - 1];
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i], A[i]--;

    auto op = [](pair<int, int> a, pair<int, int> b){
        if(a.first == b.first) return a.second < b.second ? a : b;
        return a.first > b.first ? a : b;
    };
    pair<int, int> e = {0, 0};


    SegmentTree<pair<int, int>> seg(N, op, e);
    for(int i = 0; i < M; i++){
        seg.update(A[i], {seg[A[i]].first + 1, A[i]});
        cout << seg.get(0, N).second + 1 << '\n';
    }
}