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
    vector<ll> A(N), F(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> F[i];

    sort(A.begin(), A.end(), greater<ll>());
    sort(F.begin(), F.end());

    // A[i] * F[i] の値を mid 以下にできるか
    auto check = [&](ll mid) -> bool {
        ll cnt = 0;
        for(int i = 0; i < N; i++){
            ll val = A[i] * F[i];
            // 既に mid 以下なら必要なし
            if(val <= mid) continue;
            // 必要な修行回数
            cnt += A[i] - mid / F[i];
        }
        return cnt <= K;
    };

    ll ok = 1e12 + 1, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    cout << ok << endl;
}