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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 累積和
    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];


    auto val = [&](int L, int R) -> ll {
        return S[R] - S[L];
    };

    ll ans = 0;
    int right = 0;
    // left 側を全探索
    for(int left = 0; left < N; left++){
        right = left;
        // [left, right)の和がK以上になる最小のrightを求める
        while(right < N && val(left, right + 1) < K) right++;
        ans += N - right;
    }

    cout << ans << endl;
}