#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class T>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    vector<T> data;
    F op;
    T id;

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
        for(int i = 0; i < int(v.size()); i++) data[i + n] = v[i];
        for(int i = n - 1; i > 0; i--) data[i] = op(data[i << 1 | 0], data[i << 1 | 1]);
    }
    void update(int i, T x) {
        i += n;
        data[i] = x;
        while (i > 1) {
            i >>= 1;
            data[i] = op(data[i << 1 | 0], data[i << 1 | 1]);
        }
    }
    T get(int l, int r) const {
        l += n, r += n;
        T resl = id, resr = id;
        while(l < r) {
            if (l & 1) resl = op(resl, data[l++]);
            if (r & 1) resr = op(data[--r], resr);
            l >>= 1, r >>= 1;
        }
        return op(resl, resr);
    }
    T operator [] (int i) const { return data[i + n]; }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i], A[i]--, B[i]--;
        if(A[i] > B[i]) swap(A[i], B[i]);
    }

    SegmentTree<int> seg(2 * N, [](int a, int b){ return a + b; }, 0);
    // A[i] に +1, B[i] に -1
    for(int i = 0; i < N; i++){
        seg.update(A[i], seg[A[i]] + 1);
        seg.update(B[i], seg[B[i]] - 1);
    }
    // 区間 [A[i] + 1, B[i]) の総和が非 0 なら交差している
    for(int i = 0; i < N; i++){
        if(seg.get(A[i] + 1, B[i]) != 0){
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}