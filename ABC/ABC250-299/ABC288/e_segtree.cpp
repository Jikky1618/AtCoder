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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), C(N), X(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < M; i++) cin >> X[i];

    // 絶対に買わないといけない商品 X
    vector<int> must(N + 1);
    for(int i = 0; i < M; i++){
        must[X[i] - 1] = true;
    }

    auto op = [&](ll a, ll b){
        return min(a, b);
    };

    SegmentTree<ll> seg(C, op, INF);

    // dp[i][j] := i番目まで買うかどうか決めたとき、買ったものがj個のときの最小値
    vector dp(N + 1, vector<ll>(N + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
        debug(i, j);
        if(!must[i]) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + A[i] + seg.get(i - j, i + 1));
        }
    }

    ll ans = *min_element(dp[N].begin(), dp[N].end());
    cout << ans << endl;
}