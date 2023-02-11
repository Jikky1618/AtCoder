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
    function<Monoid(Monoid, Monoid)> op;
    Monoid id;

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
    int Q;
    cin >> Q;

    auto op = [](int a, int b){
        return a + b;
    };

    SegmentTree<int> seg((int)2e6, op, 0);
    while(Q--){
        int T, X;
        cin >> T >> X;
        if(T == 1){
            seg.update(X, 1);
        }else{
            // 以下の個数(総和)がX個未満のなかで最大の数値を二分探索
            int ok = -1, ng = 2e6 + 1;
            while(ng - ok > 1){
                int mid = (ok + ng) / 2;
                if(seg.get(0, mid) < X) ok = mid;
                else ng = mid;
            }
            cout << ok << '\n';
            seg.update(ok, 0);
        }
    }
}