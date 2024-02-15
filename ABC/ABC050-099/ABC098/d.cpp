#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // 累積 xor と累積和をとる
    vector<ll> X(N + 1), S(N + 1);
    for (int i = 0; i < N; i++) {
        X[i + 1] = X[i] ^ A[i];
        S[i + 1] = S[i] + A[i];
    }

    // 区間 [l, r) が条件を満たすかどうかを判定する関数
    auto check = [&](int l, int r) -> bool {
        return (X[r] ^ X[l]) == S[r] - S[l];
    };

    // ある区間 [l, r) が条件を満たすとき, その部分区間も条件を満たす
    // よって片方を固定して二分探索
    ll ans = 0;
    for(int i = 0; i < N; i++){
        int ok = i, ng = N + 1;
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            (check(i, mid) ? ok : ng) = mid;
        }
        ans += ok - i;
    }

    cout << ans << '\n';
}