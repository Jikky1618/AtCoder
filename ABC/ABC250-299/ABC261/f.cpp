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

template <class T>
vector<T> compress(vector<T>& v) {
    int n = v.size();
    vector<T> res = v;
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (int i = 0; i < n; i++) {
        v[i] = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> C(N), X(N);
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> X[i];
    // 座圧
    compress(C);
    compress(X);

    // ボールを色ごとに管理
    map<int, vector<int>> mp;
    for(int i = 0; i < N; i++) mp[C[i]].emplace_back(X[i]);

    // すべてのボールの転倒数から各色の転倒数を引く
    auto calc = [&](vector<int>& v){
        int n = v.size();
        int m = compress(v).size();
        BinaryIndexedTree<ll> bit(m + 1);
        ll res = 0;
        for(int i = 0; i < n; i++){
            res += bit.sum(v[i] + 1, m + 1);
            bit.add(v[i], 1);
        }
        return res;
    };

    ll ans = calc(X);
    for(auto [key, val]: mp) ans -= calc(val);

    cout << ans << '\n';
}