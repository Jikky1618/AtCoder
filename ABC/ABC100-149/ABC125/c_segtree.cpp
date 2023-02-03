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
    vector<Monoid> data;
    Monoid id;
    function<Monoid(Monoid, Monoid)> op;

    SegmentTree(int size, function<Monoid(Monoid, Monoid)> operation, Monoid identity)
        : op(operation), id(identity) {
        n = 1;
        while (n < size) n <<= 1;
        data.resize(2 * n - 1, id);
    }

    SegmentTree(const vector<Monoid> &vec, std::function<Monoid(Monoid, Monoid)> operation, Monoid identity)
        : op(operation), id(identity) {
        n = 1;
        while (n < vec.size()) n <<= 1;
        data.resize(2 * n - 1, id);
        for (int i = 0; i < vec.size(); i++) {
            data[i + n - 1] = vec[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            data[i] = op(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    void update(int k, Monoid x) {
        k += n - 1;
        data[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = op(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    // 再帰関数による区間取得
    Monoid get(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return id;
        if (a <= l && r <= b) return data[k];

        Monoid vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
        Monoid vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return op(vl, vr);
    }

    // 区間[a, b)の取得
    Monoid get(int a, int b) {
        return get(a, b, 0, 0, n);
    }

    // 一点取得
    Monoid get(int k) {
        return data[k + n - 1];
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    auto op = [](int a, int b){
        return gcd(a, b);
    };

    SegmentTree<int> seg(A, op, 0);
    int ans = 0;
    for(int i = 0; i < N; i++){
        int G = 0;
        G = gcd(G, seg.get(0, i));
        G = gcd(G, seg.get(i + 1, N));
        ans = max(ans, G);
    }

    cout << ans << endl;
}