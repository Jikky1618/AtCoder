#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 3e5 + 1;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

ll naive(int N, vector<int>& A) {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i] == A[k] && A[i] != A[j]) ans++;
            }
        }
    }
    return ans;
}

ll solve(int N, vector<int>& A) {
    // 後ろから見る
    ll ans = 0;
    // cnt[i] := A[i] が出現した場所の集合
    vector<vector<ll>> cnt(MAX);
    vector<ll> cnt2(MAX);  // 差分の総和
    for (int i = N - 1; i >= 0; i--) {
        ll cnts = cnt[A[i]].size();
        if (cnts != 0) cnt2[A[i]] += (cnt[A[i]].back() - i - 1) * cnts;
        if (i + 2 < N && cnts) {
            ans += cnt2[A[i]];
        }
        cnt[A[i]].emplace_back(i);
    }
    return ans;
}

int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
mt19937_64 rnd(seed);
template <class T>
// V := 生成する配列, N := 配列の大きさ, unique := 重複なしか
void generate_vector(vector<T>& V, int N = -1, bool unique = false) {
    // dist_N(l, r) := [l, r] の範囲で乱数を生成
    uniform_int_distribution<T> dist_N(3, 10);

    // N が指定されていないなら, 乱数生成
    if (N == -1) N = dist_N(rnd);

    // dist_V(l, r) := [l, r] の範囲で乱数を生成
    uniform_int_distribution<T> dist_V(1, N);
    V.assign(N, 0);
    // 重複ありの場合
    if (!unique) {
        for (int i = 0; i < N; i++) V[i] = dist_V(rnd);
    // 重複なしの場合
    } else {
        unordered_set<T> st;
        int pos = 0;
        while (pos < N) {
            T val = dist_V(rnd);
            if (st.count(val)) continue;
            st.insert(val);
            V[pos++] = val;
        }
    }
    debug(V, N);
    return;
}
void check() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> A;
        generate_vector(A);
        int N = A.size();

        if (naive(N, A) != solve(N, A)) {
            debug(N, A);
            debug(naive(N, A), solve(N, A));
            return;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    // int N;
    // cin >> N;
    // vector<int> A(N);
    // for(int i = 0; i < N; i++) cin >> A[i];
    // cout << solve(N, A) << endl;

    vector<int> A;
    for(int t = 0; t < 1000; t++){
        generate_vector(A, 2e6, true);
        if(t < 3) debug(A);
    }
}