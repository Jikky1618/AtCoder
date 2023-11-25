#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class Abel>
struct BinaryIndexedTree {
    int n;
    vector<Abel> dat;
    Abel UNITY_SUM = 0;

    BinaryIndexedTree(int size, Abel unity = 0)
        : n(size), dat(size, unity), UNITY_SUM(unity) {}

    BinaryIndexedTree(const vector<Abel>& vec, Abel unity = 0)
        : n(vec.size()), dat(n, unity) {
        for (int i = 0; i < n; i++) add(i, vec[i]);
    }

    // val[a] += x
    void add(int a, Abel x) {
        for (int i = a; i < n; i |= i + 1) {
            dat[i] += x;
        }
    }

    // 区間 [0, a) の取得
    Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1) {
            res += dat[i];
        }
        return res;
    }

    // 区間 [a, b) の取得
    Abel sum(int a, int b) { return sum(b) - sum(a); }

    Abel all() { return dat.front(); }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> cnt(N);
    for(int i = 0; i < N; i++) if(A[i] < N) cnt[A[i]]++;
    BinaryIndexedTree<int> bit(N);
    for(int i = 0; i < N; i++) if(cnt[i]) bit.add(i, 1);

    while(Q--){
        int i, x; cin >> i >> x, i--;
        if(A[i] < N) {
            if(cnt[A[i]] == 1) bit.add(A[i], -1);
            cnt[A[i]]--;
        }
        A[i] = x;
        if(A[i] < N) {
            if(cnt[A[i]] == 0) bit.add(A[i], 1);
            cnt[A[i]]++;
        }

        int ok = -1, ng = N + 1;
        debug(A);
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            debug(bit.sum(mid), mid);
            // [0, mid) が全て揃っていれば mex は mid 以上
            (bit.sum(mid) == mid ? ok : ng) = mid;
        }

        cout << ok << '\n';
    }
}