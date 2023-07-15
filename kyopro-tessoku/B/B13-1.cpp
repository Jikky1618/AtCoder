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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 累積和
    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    debug(S);
    ll ans = 0;
    // 累積和配列をしゃくとり
    for(int left = 0, right = 0; left < N; left++){
        right = max(left, right);
        // 連続する区間 [left, right) をしゃくとり
        // while 文の条件: [left, right + 1) の総和が K 以下
        // (A[right] を追加しても総和が K 以下)なら right を動かす
        while(right < N && S[right + 1] - S[left] <= K) right++;
        debug(left, right, S[right] - S[left], right - left);
        ans += right - left;
    }

    cout << ans << endl;
}