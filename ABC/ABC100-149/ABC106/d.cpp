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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<tuple<int, int, int>> query;
    // M 個の列車区間 {L, R, -1}
    for(int i = 0; i < M; i++){
        int L, R; cin >> L >> R, L--, R--;
        query.emplace_back(L, R, -1);
    }
    // Q 個のクエリ {p, q, id}
    for(int i = 0; i < Q; i++){
        int p, q; cin >> p >> q, p--, q--;
        query.emplace_back(p, q, i);
    }

    // 区間の右端でソート (列車区間を優先)
    auto comp = [&](auto a, auto b) -> bool {
        auto [l1, r1, t1] = a;
        auto [l2, r2, t2] = b;
        if(r1 == r2) return t1 < t2;
        return r1 < r2;
    };
    sort(query.begin(), query.end(), comp);
    debug(query);

    BinaryIndexedTree<int> bit(N);
    vector<int> ans(Q);
    for(auto [l, r, t] : query){
        // 列車区間の場合
        if(t == -1){
            bit.add(l, 1);
        // t 番目のクエリの答えを求める
        }else{
            ans[t] = bit.sum(l, r + 1);
        }
    }

    for(int i = 0; i < Q; i++){
        cout << ans[i] << '\n';
    }
}