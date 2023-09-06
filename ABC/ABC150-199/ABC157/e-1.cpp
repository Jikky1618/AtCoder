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

    SegmentTree(const vector<Monoid> &vec, std::function<Monoid(Monoid, Monoid)> operation, Monoid identity)
        : op(operation), id(identity) {
        n = 1;
        while (n < vec.size()) n <<= 1;
        dat.resize(2 * n - 1, id);
        for (int i = 0; i < vec.size(); i++) {
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
            k = (k - 1) / 2;
            dat[k] = op(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    // 再帰関数による区間取得
    Monoid get(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return id;
        if (a <= l && r <= b) return dat[k];

        Monoid vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
        Monoid vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
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
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    
    auto op = [](int a, int b){
        return a + b;
    };

    vector seg(26, SegmentTree<int>(N, op, 0));
    for(int i = 0; i < N; i++){
        seg[S[i] - 'a'].update(i, 1);
    }

    while(Q--){
        int type; cin >> type;
        if(type == 1){
            int i; char c; cin >> i >> c, i--;
            seg[S[i] - 'a'].update(i, 0);
            seg[c - 'a'].update(i, 1);
            // 文字列の更新
            S[i] = c;
        }
        if(type == 2){
            int l, r; cin >> l >> r, l--;
            int ans = 0;
            for(int i = 0; i < 26; i++){
                if(seg[i].get(l, r) > 0) ans++;
            }
            cout << ans << '\n';
        }
    }
}