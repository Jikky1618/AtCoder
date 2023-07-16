#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;

    // S にある x の個数の累積和
    vector<ll> acc(N + 1);
    for(int i = 0; i < N; i++) acc[i + 1] = acc[i] + (S[i] == 'x');
    debug(acc);
    debug(acc[9] - acc[0]);

    ll ans = 0;
    for(int l = 0; l < N; l++){
        auto check = [&](ll mid) -> bool {
            ll sum = 0; // sum := 区間 [l, mid) にある x の数
            // イメージとしては, [0, mid) - [0, l) をしている
            // [0, kN) に含んでる S の数 × S にある x の個数 + [kN, mid) の x の個数(k = ⌊mid / N⌋)
            sum += (mid / N) * acc[N] + acc[mid % N];
            // [0, l) にある x の個数を引き算
            sum -= acc[l];
            debug(l, mid, sum, K);
            return sum <= K;
        };

        // l を固定したとき,[l, r) に x が K 個以下になる最大の r を全探索
        ll ok = l - 1, ng = N * M + 1;
        while(ng - ok > 1){
            ll mid = (ok + ng) / 2;
            (check(mid) ? ok : ng) = mid;
        }
        ans = max(ans, ok - l);
    }

    cout << ans << endl;
}